<p align="center">
  <img src="https://indo-ware.com/logo/LOGONEW2.png" alt="Indoware logo"/>
</p>

# Contoh kode gps-ct1612ub

Cara membaca data latitude, longitude dan jam satelit dengan mikrokontroller AVR dan menampilkannya di LCD pemograman dengan CodeVisionAVR 2.05.3 Pada listing code ini terdapat cara memisahkan memilih, memisahkan, dan menampilkan data tersebut pada LCD 16x2.

## Data GPS NMEA GLL
GPS ini mengeluarkan lima data yang berbeda dengan protokol NMEA, tetapi yang kita ambil hanya data GLL yang mempunyai format sebagai berikut

$GPGLL , 3723.2475, N,12158.3416, W,161229.487, A*2C.

dimana
$GPGLL    -> Header protokol GPGLL
3723.2475 -> data <i>latitude</i>
N         -> indikator North atau South
12158.3416-> data <i>longitude</i>
W         -> Indikator West atau East
161229.487-> Data jam satelit dalam UTC+0
A         -> A : data valid V : data tidak valid
2c        -> Checksum

format data latitude:
3723.2475
Ddmm.mmmmm

format data Longitude:
12158.34161
Ddmm.mmmmm

format data jam UTC:
161229.487
Hhmmss.sss

## Perangkat Yang Digunakan
<ol>
<li>Modul ATmega32 dengan Frekuensi Crystal 16MHz</li>
<li>GPS t1612ub </li>
<li>LCD 16x2</li>
<li>Regulator 3V LP2950</li>
</ol>

## Deskripsi Kerja Program


<p><b>by Arief Ismail</b></p>
<p><b>Copyright Indo-Ware</b></p>
