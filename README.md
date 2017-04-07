<p align="center">
  <img src="https://indo-ware.com/logo/LOGONEW2.png" alt="Indoware logo"/>
</p>
 <p><img src="https://ecs7.tokopedia.net/img/product-1/2017/4/7/2399406/2399406_bd790ec1-7a6a-49ab-96ae-06252f91667f_2048_0.jpg""/></p>
# Introduction gps-ct1612ub

</p>Cara membaca data latitude, longitude dan jam satelit dengan mikrokontroller AVR dan menampilkannya di LCD pemograman dengan CodeVisionAVR 2.05.3 Pada listing code ini terdapat cara memisahkan memilih, memisahkan, dan menampilkan data tersebut pada LCD 16x2.</p>

## Data GPS NMEA GLL
<p>GPS ini mengeluarkan lima data yang berbeda dengan protokol NMEA, tetapi yang kita ambil hanya data GLL yang mempunyai format sebagai berikut</p>

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
<ol>
<li>Modul ATmega32 dengan Frekuensi Crystal 16MHz</li>
<li>GPS t1612ub </li>
<li>LCD 16x2</li>
<li>Regulator 3V LP2950</li>
</ol>

<p>LCD disambungkan pada PORTA modul dan kaki TX pada GPS disambungkan pada PORT RX ATmega32 yaitu PORTD.0</p>

## Deskripsi Kerja Program
<p>Pada saat Modul dinyalakan maka maka Mikrokontroller akan menunggu hingga mendapatkan data GLL. setelah data didapatkan maka LCD akan menampilkan data longitude dan latitude telebih dahulu selama 3 detik kemudian dilanjutkan dengan data jam yang telah disesuaikan dengan zona waktu masing-masing dengan rumus perhitungan bujur.</p>

##
<p align="right" size"6"><b>by Arief Ismail</b></p>
<p align="right" size"6"><b>Copyright Indo-Ware</b></p>
