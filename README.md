<p align="center">
  <img src="https://indo-ware.com/logo/LOGONEW2.png" alt="Indoware logo"/>
</p>
# Introduction gps-ct1612ub
  <img align="middle" src="https://lh3.googleusercontent.com/U8BbwVDq1qoQIpUevqF-B64Ver6GkTOeiSkpAqmdpOhtz8tBcdv2FjQgheMJrcPF3zTNn23XHU2ZPWyRCJzQfu6ilk5Mu4I_70nT0RPOVmTcEdsGX1QuzFi_261BVqgfS5aM0MgtpRaLTKg-4rg6rqiIG_iBfZwqLqSKcYTlLy4e9qUGcPpCYYJJJ5Q7RUs4acwQKfQ2Lg0C_ddm3EP3CS42IZOTymhDSdnzk73mbQ9L2XO3bswvhQWo1XidKbBqppd3-IvdPPszttMpEQXc0msZShMc9aJzVnXljhIJDA0mIrj7e313oXOOfj-08JgNsz9ZQhCsqLuxgfJzc_dm1HBzPNWPSvA2xr49Btdg2uyslF8nXGiyhJswCvN3ihpS6MVsEuIO45aFJQlS_LtiK6nqgwFTnQrOViGrrWiCT24-F2-v4T6nh98loYHQf7-ePx-fET3Nj4jzNxWZ3hlEPMWvOC8DTMX8M0MDy1VLp0VyndHRb_CMmYQ0Avo3oTE_GY7jrxis0wnIsrLQHn6Jm7waIGMokr6aNPJxFsBk6m_EO8OCrVPUHGD3x2ESXG8gB57xvtVxzXDtls6Bp3UndroI6-WO0y5Ka0zehiiQyuMDf01Rf8w=w1366-h490-no"/>
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
<img align="middle" src="https://lh3.googleusercontent.com/ZS723IVPzSMDAesGnyGehAhpeujc_DUZQxnX9KTWznYnYkw5rHCmlqyKrKkDq_MrFQN73f4WxZhefixeZWqho_f4AmeKtoKjCKqRHpNy8FiWEhzauzdq4XNTI6UVFCa8mFxq418xTwMvvGubVOjPs98LY1imOdjsxlTZLHS8ItDQKNanVsqS0EJXMabNlq9VBknaeTgNTn99ftIPP74NI0BX2eLc5Mt8HFVW3VRFdbm4UBD8amXS84MbzHQzTnWKM4QaPYRPDuaa-iBHfXuitt4XcIxU_FEJFZkzrsA0egMS20wd2urd-gSDBhNGgrwlbDI1epm_9WGjEY4_5bxhASHs8_NeVMPWDPio8L3mmTfkg8QIRxcX2BVFb-bRSB7fLMrTW02q778_-bpTkngyUV-bcOwniPL-WlTsiXr1RezbPO5C24khxwXgLDiZMc6JGysum08P9TJV1wATt87XGRgRIrcQauCIdlz0w961oP4oCXFWG10POf2IGrB_toiugOxEf_N-VHyPRjUgOhgPQdZO3VQxbMJCAvDv5G7kKcTm7CrVsWoNyPboWabPZhhsG1n0k-HODfyvH7TF7vOllGMtLS-iTEu_QjWyFsJaCWH0ZifzJ04=w943-h613-no"/>
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
<img align="middle" src="https://lh3.googleusercontent.com/O-FYBNM5CH-HOuBQEkwXrEGFXCPEjWjjFNmYKY7nwqnv4f8LfmPP3alo--OhqgjxpWKSW7QE26nSR9ZwqAMxHFMk8vgQ3saoOqBac7ooHJPNRohrYi1jQJwCHcWqsxN9urGs5GRBMPBdKvlLCU9sCDAq9W7oDeW2FS5GgGSPXcCa4OmSeYROgOImn5OikaUzqL4_SxuMfU5Xc8dpndZhSAOb2pugewDthDXcHthNWAbpoLTmN7TAV2GUwReydzFGOj-cfrdb49-twOcuN62yHGLFYCYEYfFdH4G2HAg-dP2kSMnYGcnGH1TdoK-wW-fjooT8ffDItN0KoB9M8QU9AWkJDcphE3qugDYRMvmlA7t9xcuQI0Ygw6oCvWju_F8FAcK3yzTdMURMmiBrMdLZPBTVj84r6CiEpUO4t9OakzsMPPWX2BMpZhubx5NzmD4b78tT4rQ1BatORznBBMaHIrecyu4aUKZSBDKyz25UyTRND2xaA2r4LW7vQ8poG0g6mFZ73kOnKd8HWPw7EGy3P5xAdVv6dSKNdRhhkS81SqwOdEfR-hsEM9Q37SeJogt97UgNxoDlQCzbHIjRRPqVfoP77oWpCsjZJztmAVhaeWjl89Y=w1090-h613-no"/>

<p><b>Pembacaan Jam dan Zona Waktu</b></p>
<img align="middle" src="https://lh3.googleusercontent.com/2EX_PhnCzEt0oEff0Lw7D8rqmJEPtFUbZYA1sXnso7eZJNWT_5yC3XJ6Zl9H9x0K6kk_ZUzoT31TeZKhOdx2b6SEaQhK18VcAGfKgY95CUf8Cx7MWqEElIY7lmN9tVZ093eFfKEbxbczW3GvAfQsVyYMBRCahG5vK4Vw4ECoKTNeqa3KmV0MX5zvhnlvmuHaZ0G7CAep90_fQcFOQrOgQxS56_9-4MLofzsMC0Ah4j0B69i5a4_9CIaUYWR_i9PjwxDXpXOisHkCkwIQVOdTTcwu9hAl_3MliNwwK2HwBOTk_dr66BMvep2qWS-peoJKMElQqR3Nk3qiDK4jRuU2KvTfUvPUynA0MPmAwdOZZrSffL1dQhMT6zlaMUvU7LJJ1RrRuffBWJHhwcRxcFt78HO130GjIvY-pwsZ9sWEFtayP8TiSYNyBMBi9BEb2fyjaLWWwise9tWGMzQ8e1YQRYr08-0D7uRh93VBiCLhwVB6QDvL01ELuN2SiZjflTmRBUo05wjxhGA0E7Kn4SXXrnL5pBzJlAVsN9VeIXgYOLDSz-lgW_q0RD38l7_KDol0YNkB5unygG32FJjMOJTjNHNNqQ-PXdNcFLZvJs6n6uwc-1fB74Y=w1090-h613-no"/>

##
<p align="right" size"6"><b>by Arief Ismail</b></p>
<p align="right" size"6"><b>Copyright Indo-Ware</b></p>
