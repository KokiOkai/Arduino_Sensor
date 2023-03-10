# Arduino_Sensor
**Arduino_Sensor**は、Arduinoとセンサを用いて構成する、気温・湿度・気圧の計測デバイス用プログラムです。<br>
<br>

## 目次
- [概要](#概要)
- [計測デバイス](#計測デバイス)
  - [必要な機材](#必要な機材)
  - [Arduino NANO](#Arduino-NANO)
  - [気象観測センサモジュール（BME280）](#気象観測センサモジュール（BME280）)
  - [SDカードモジュール](#SDカードモジュール)
- [開発環境](#開発環境)
  - [開発環境のインストール](#開発環境のインストール)
  - [開発環境の設定](#開発環境の設定)
  - [BME280ドライバの導入](#BME280ドライバの導入)
- [計測用プログラムの仕様](#計測用プログラムの仕様)
  - [電源投入時](#電源投入時)
  - [計測時](#計測時)


## 概要
**Arduino_Sensor**は、Arduinoとセンサを用いて構成する、気温・湿度・気圧の計測デバイス用プログラムです。<br>
Arduino専用の統合開発環境（IDE）をインストールする必要があります。<br>
Arduinoの開発にはC言語が用いられています。


## 計測デバイス
### 必要な機材
- Arduino NANO：1個
- 気象観測センサモジュール（BME280）：1個
- SDカードモジュール：1個
- Micro SDカード（32GB以下）：1個
- ブレッドボード：1個
- タクトスイッチ：1個
- 10kΩ抵抗：1個
- 1kΩ抵抗：1個
- 青色LED：1個
- ケーブル（USB Type-A ⇔ Micro USB Type-B）：1個
- ジャンピングワイヤー（オス－オス）
- ジャンピングワイヤー（オス－メス）

### Arduino NANO
Arduinoは、Atmel社が開発したRISCベースの8bitマイクロコントローラです。<br>
Arduinoには専用の統合開発環境（IDE）が用意されており、これを使うことで簡単に組込みシステムやIoTを学習することができます。<br>
使用する機材は、[Arduino NANO](https://store-usa.arduino.cc/products/arduino-nano/)です。

<img src="https://user-images.githubusercontent.com/105481222/218243370-ba12f5e0-2bc8-4940-895f-f8c322819a36.jpg" width="30%">
<img src="https://user-images.githubusercontent.com/105481222/218243513-00cad4d9-73d2-409c-a94e-62d45b7c45f3.jpg" width="50%">

### 気象観測センサモジュール（BME280）
BOSCH社のBME280を搭載した環境測定センサモジュールであり、気温・湿度・気圧の3つの環境情報を同時に計測することができます。<br>
BME280では、マイコンとの通信方式としてI2CまたはSPIをサポートしています。<br>
本プログラムでは、インターフェースとしてI2Cを用いることを想定しています。

<br>
<img src="https://user-images.githubusercontent.com/105481222/218245608-8fbaba36-5758-4598-a51d-9201fee508c5.jpg" width="30%">
<img src="https://user-images.githubusercontent.com/105481222/218245691-f0bd3f5f-20c4-4b2c-bc0c-75650d625a0f.jpg" width="50%">

### SDカードモジュール
計測したデータを記録するために、SDカードモジュールを使用します。<br>
本プログラムでは、インターフェースとしてSPIを用いることを想定しています。

<img src="https://user-images.githubusercontent.com/105481222/218246642-72687138-7596-4df8-9cd3-db0aa7f727cd.jpg" width="30%">

### 回路図
Arduino NANOに、BMEセンサモジュールをI2Cインタフェースを用いて、<br>
SDカードモジュールをSPIインタフェースを用いて接続します。

<img src="https://user-images.githubusercontent.com/105481222/220910289-6179c7bb-d0c5-4a24-8c26-edd034809189.jpg" width="50%">


## 開発環境
### 開発環境のインストール
Arduinoを用いてデバイスを開発するためには、専用の統合開発環境（IDE）が必要となります。<br>
1. Arduinoの公式Webサイト（[https://www.arduino.cc/](https://www.arduino.cc/)）を開く。<br>
2. 画面上部のメニューバーの「SOFTWARE」を開く。<br>
3. パソコンのOSに合っているものをダウンロードする。

### 開発環境の設定
Arduino IDEはすべてのArduinoに対応した開発環境であるため、開発プロジェクトに合わせて、開発環境のパラメータを設定する必要があります。<br>
画面上部のメニューバーから「ツール」を開き、
- 「ボード」を開き、「Arduino Nano」を設定する。
- 「プロセッサ」を開き、「ATmega328P」を設定する。（互換品を用いる場合は「ATmega328P（Old Bootloader）」）<br>
- Arduino NANOとパソコンをUSB接続した状態で、「シリアルポート」を確認する。
  - Windows環境の場合は「COM x（xの部分に数字）」
  - MacOS環境の場合は「/dev/cu.usbserial-xxxx（xxxxの部分にはデバイス名など）」
- 「書込装置」を開き、「USBasp」を設定する。

### BME280ドライバの導入
現在、BME280を含むBME系のセンサデバイスについては、様々な企業や団体から開発用のライブラリが提供されています。<br>
本プログラムでは、SparkFunのライブラリを使用します。
1. 画面上部のメニューバーから「ツール」を開き、「ライブラリを管理」を開く。
2. 「タイプ」「トピック」をいずれも「全て」として、検索ウィンドウに「SparkFun BME280」と入力する。
3. リストアップされたSparkFun BME280のドライバをインストールする。


## 計測用プログラムの仕様
### 電源投入時
- 電源投入時に青色LEDが点灯します。
- SDカードモジュールに挿入されているMicro SDカードを読み込みます。
- Micro SDカードの読み込みに成功すると、スタンバイ状態になります。

### 計測時
- タクトスイッチを押すと青色LEDが消灯し、計測を開始します（計測状態）。
- 計測を1分毎に行います。
- 計測されたデータの出力形式は「計測ID（4桁の通し番号）, 気温, 湿度, 気圧」です。
- 計測結果を1つのCSVファイルとして保存します（ファイル名は8文字以内）。
- 再度タクトスイッチを押すと、計測が一時停止します。青色LEDが点灯してスタンバイ状態になります。

