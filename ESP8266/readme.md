# <b>ESP8266</b>
<p>
  Folder untuk menyimpan file sketch ESP8266 basic. mungkin dibutuhkan dilain waktu. 
</p>
<p>
  Pinout Reference
</p>
<table>
  <tr>
    <th>Board Pin</th>
    <th>GPIO</th>
    <th>INPUT</th>
    <th>OUTPUT</th>
    <th>Info</th>
  </tr>
  <tr>
    <td>D0</td>
    <td>GPIO16</td>
    <td>-</td>
    <td>-</td>
    <td>HIGH at BOOT</td>
  </tr>
  <tr>
    <td>D1</td>
    <td>GPIO5</td>
    <td>OK</td>
    <td>OK</td>
    <td>As SCL (I2C)</td>
  </tr>
  <tr>
    <td>D2</td>
    <td>GPIO4</td>
    <td>OK</td>
    <td>OK</td>
    <td>As SDA (I2C)</td>
  </tr>
  <tr>
    <td>D3</td>
    <td>GPIO</td>
    <td>Pullep UP</td>
    <td>OK</td>
    <td>Connected to FLASH, BOOT fail if pulled low</td>
  </tr>
  <tr>
    <td>D4</td>
    <td>GPIO2</td>
    <td>Pullep UP</td>
    <td>OK</td>
    <td>Connected to LED, HIGH at BOOT, BOOT fail if pulled low</td>
  </tr>
  <tr>
    <td>D5</td>
    <td>GPIO14</td>
    <td>OK</td>
    <td>OK</td>
    <td>SCK (SPI)</td>
  </tr>
  <tr>
    <td>D6</td>
    <td>GPIO12</td>
    <td>OK</td>
    <td>OK</td>
    <td>MISO (SPI)</td>
  </tr>
  <tr>
    <td>D7</td>
    <td>GPIO13</td>
    <td>OK</td>
    <td>OK</td>
    <td>MOSI (SPI)</td>
  </tr>
  <tr>
    <td>D8</td>
    <td>GPIO13</td>
    <td>Pulled LOW</td>
    <td>OK</td>
    <td>CS (SPI)</td>
  </tr>
  <tr>
    <td>RX</td>
    <td>GPIO3</td>
    <td>OK</td>
    <td>RX Pin</td>
    <td>HIGH at BOOT</td>
  </tr>
  <tr>
    <td>TX</td>
    <td>GPIO1</td>
    <td>OK</td>
    <td>TX Pin</td>
    <td>HIGH at BOOT</td>
  </tr>
  <tr>
    <td>A0</td>
    <td>ADC0</td>
    <td>Analog Input</td>
    <td>-</td>
    <td>-</td>
  </tr>
</table>
