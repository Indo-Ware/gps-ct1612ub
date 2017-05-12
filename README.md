<p align="center">
  <img src="https://indo-ware.com/logo/LOGONEW2.png" alt="Indoware logo"/>
</p>

# Introduction gps-ct1612ub

  <img align="middle" src="https://github.com/Indo-Ware-org/gps-ct1612ub/blob/master/image/IMAG0560.jpg"/>
<p>Pada <i>readme</i> ini akan dijelaskan cara membaca data latitude, longitude dan jam satelit dengan modul mikrokontroller AVR ATmega328P IndoWare dan menampilkannya di LCD pemograman dengan CodeVisionAVR 2.05.3 Pada listing code ini terdapat cara memisahkan memilih, memisahkan, dan menampilkan data tersebut pada LCD 16x2.</p>

## Data GPS NMEA GLL
<p>Berdasarkan datasheet dari <a href="https://raw.githubusercontent.com/SeeedDocument/Grove-GPS/master/res/E-1612-UB_Datasheets_Sheet.pdf">CT1612UB</a> GPS ini mengeluarkan lima data yang berbeda dengan protokol NMEA, tetapi yang kita ambil hanya data GLL yang mempunyai format sebagai berikut</p>

<p>$GPGLL , 3723.2475, N,12158.3416, W,161229.487, A*2C.</p>

<p>dimana</p>

<ul>
<li>$GPGLL    -> Header protokol GPGLL</li>
<li>3723.2475 -> data <i>latitude</i></li>
<li>N         -> indikator North atau South</li>
<li>12158.3416-> data <i>longitude</i></li>
<li>W         -> Indikator West atau East</li>
<li>161229.487-> Data jam satelit dalam UTC+0</li>
<li>A         -> A : data valid V : data tidak valid</li>
<li>*2c       -> Checksum</li>
</ul>

<p>format data latitude:</p>
<p>3723.2475</p>
<p>Ddmm.mmmmm</p>

<p>format data Longitude:</p>
<p>12158.34161</p>
<p>Ddmm.mmmmm</p>

<p>format data jam UTC:</p>
<p>161229.487</p>
<p>Hhmmss.sss</p>

## Perangkat Yang Digunakan
<img align="middle" src="https://github.com/Indo-Ware-org/gps-ct1612ub/blob/master/image/IMAG0559.jpg"/>
<ol>
<li>1. Modul ATmega328P dengan sumber clock internal 8MHz</li>
<li>GPS ct1612ub</li>
<li>LCD 16x2</li>
<li>Regulator 3V LP2950</li>
</ol>

<p>LCD disambungkan pada PORTB modul dan kaki TX pada GPS disambungkan pada PORT TX ATmega328P</p>

## Deskripsi Kerja Program
<p>Pada saat Modul dinyalakan maka maka Mikrokontroller akan menunggu hingga mendapatkan data GLL. setelah data didapatkan maka LCD akan menampilkan data longitude dan latitude telebih dahulu selama 3 detik kemudian dilanjutkan dengan data jam yang telah disesuaikan dengan zona waktu masing-masing dengan rumus perhitungan bujur. Tampilan pada LCD akan menjadi seperti berikut</p>

<p><b>Pembacaan Latitude dan Longitude</b></p>
<img align="middle" src="https://github.com/Indo-Ware-org/gps-ct1612ub/blob/master/image/IMAG0556.jpg"/>

<p><b>Pembacaan Jam dan Zona Waktu</b></p>
<img align="middle" src="https://github.com/Indo-Ware-org/gps-ct1612ub/blob/master/image/IMAG0557.jpg"/>

##
<p align="right" size"6"><b>by IRP</b></p>
<p align="right" size"6"><b>Copyright Indo-Ware</b></p>
