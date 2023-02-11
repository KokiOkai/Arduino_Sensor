# Arduino_Sensor
**Arduino_Sensor**は、Arduinoとセンサを用いて構成する、気温・湿度・気圧の計測デバイス用ライブラリです。<br>
<br>


## 目次
- [概要](#概要)
- [計測デバイス](#計測デバイス)
- [動作環境](#動作環境)
- [インストール方法](#インストール方法)
- [ライブラリの使い方](#ライブラリの使い方)


## 概要
**Arduino_Sensor**は、Arduinoとセンサを用いて構成する、気温・湿度・気圧の計測デバイス用ライブラリです。<br>
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
Arduino Nano<br>

<br>
<img src="https://user-images.githubusercontent.com/105481222/218243513-00cad4d9-73d2-409c-a94e-62d45b7c45f3.jpg" width="50%">
ピン配置<br>

### 気象観測センサモジュール（BME280）
BOSCH社のBME280を搭載した環境測定センサモジュールであり、気温・湿度・気圧の3つの環境情報を同時に計測することができます。<br>
BME280では、マイコンとの通信方式としてI2CまたはSPIをサポートしています。<br>
本ライブラリでは、インターフェースとしてI2Cを用いることを想定しています。

<br>
<img src="https://user-images.githubusercontent.com/105481222/218245608-8fbaba36-5758-4598-a51d-9201fee508c5.jpg" width="30%">
気象観測センサモジュール（BME280）<br>

<br>
<br>
<img src="https://user-images.githubusercontent.com/105481222/218245691-f0bd3f5f-20c4-4b2c-bc0c-75650d625a0f.jpg" width="50%">
回路図<br>

### SDカードモジュール
計測したデータを記録するために、SDカードモジュールを使用します。
本ライブラリでは、インターフェースとしてSPIを用いることを想定しています。

<img src="https://user-images.githubusercontent.com/105481222/218246642-72687138-7596-4df8-9cd3-db0aa7f727cd.jpg" width="30%">
SDカードモジュール<br>


## 動作環境


## インストール方法


## ライブラリの使い方
