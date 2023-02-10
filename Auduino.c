// I2Cによるデバイスへのアクセス
#include <Wire.h>

// BME280モジュールへのアクセス
#include "SparkFunBME280.h"

// SPIによるデバイスへのアクセス
#include <SPI.h>

// SDカードモジュールへのアクセス
#include <SD.h>

// 標準入出力に使われる関数の宣言をできるようにする
#include <stdio.h>

// BME280に関する関数の宣言をできるようにする
BME280 sensor;


const int led = 2;         // LEDのピン番号
const int chipSelect = 4;  // CS(Chip Select)のピン番号
const int t_Switch = 7;    // タクトスイッチのピン番号

int state = 0;                   // タクトスイッチのピンより取得したデータ格納用
int measurementID = 0;           // 計測ID
unsigned long previousTime = 0;  // 前回実行した時刻
unsigned long currentTime = 0;   // 実行してからの現在時刻
unsigned long interval = 60000;  // 計測間隔（1分）
boolean work = false;            // 計測動作判定


void setup() {
    Serial.begin(9600);               // シリアルモニタ出力レート
    // シリアルポートの準備ができるのを待つ
    while (!Serial) {
      ;
    }
    Wire.begin();                     // I2Cの初期化
    sensor.setI2CAddress(0x76);       // I2Cアドレスを設定
    sensor.beginI2C();                // Wireを用いてI2C接続開始
    
    pinMode(t_Switch, INPUT);         // タクトスイッチを入力に設定
    pinMode(led, OUTPUT);             // LEDを出力に設定
    pinMode(chipSelect, OUTPUT);      // Chip Selectを出力に設定
    
    digitalWrite(led, HIGH);          // 電源を入れたときにLEDを点灯（スタンバイ状態）
    Serial.println("Arduino起動");
    Serial.println("SDカードを読み込みます..."); 
     
    // SDカードが利用可能かどうか確認
    if (!SD.begin(chipSelect)) {
        Serial.println("SDカード読み取りに失敗しました");
        while(1);
    } else {
        Serial.println("SDカード読み取りに成功しました");
        Serial.println("タクトスイッチを押すと計測を開始します");
    }
}

void loop() {
    state = digitalRead(t_Switch);  // タクトスイッチのピンよりデータ取得
    // 取得データにより分岐
    if (state == LOW) {  // タクトスイッチ押したとき
        work = !work;    // 計測動作判定 true→false、false→true
        if (work) {
            Serial.println("計測開始");
            digitalWrite(led, LOW);  // LEDを消灯
        } else {
            Serial.println("計測停止");
            digitalWrite(led, HIGH);  // LEDを点灯
        }
        // 処理を2秒遅らせることで、タクトスイッチの誤検出防止
        delay(2000);
    }
  
    // 計測処理
    if (work) {
        unsigned long currentTime = millis();  // 実行してからの現在時刻を取得
        if ((currentTime - previousTime) >= interval) {
            File dataFile = SD.open("test.csv", FILE_WRITE);  // ファイルを開く、なければ新規作成
            if (dataFile) {
                // シニアルモニタに「計測ID,気温,湿度,気圧」を表示する
                // SDカードにデータを記録する
                measurementID = measurementID + 1;
                Serial.print(strPad(measurementID));
                dataFile.print(strPad(measurementID));
              
                Serial.print(", ");
                dataFile.print(", ");
                Serial.print(sensor.readTempC(), 2);
                dataFile.print(sensor.readTempC(), 2);
              
                Serial.print(", ");
                dataFile.print(", ");
                Serial.print(sensor.readFloatHumidity(), 2);
                dataFile.print(sensor.readFloatHumidity(), 2);
              
                Serial.print(", ");
                dataFile.print(", ");
                Serial.println(sensor.readFloatPressure() / 100.0, 1);
                dataFile.println(sensor.readFloatPressure() / 100.0, 1);

                dataFile.close();  // ファイルを閉じる
    
                previousTime = currentTime;  // 前回実行時刻を現在時刻で更新
            } else {
                Serial.println("データファイルを開くことができません");
            }
        }
    }   
}

// 計測ID作るメソッド
String strPad(int num) {
    char tmp[256];
    char param[] = "%04d\0";
    sprintf(tmp,param,num);
    return tmp;
}
