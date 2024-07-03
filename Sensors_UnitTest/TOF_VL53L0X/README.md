# TOF_VL53L0X

### Dependencies:

- Go to `Library Manager`, Install `Adafruit_VL53L0X` by `Adafruit`

- Upload the `VL53L0X` Sketch from `Examples`

- Carefully Connect esp32 with MPU :
    - `SCL` to `GPIO 22`
    - `SDA` to `GPIO 21`
    - `VCC` to `5v or 3.3v`
    - `GND` to `GND`

----

> Now you got 3 TOF sensors with the same address `0x29`
- you had to change for each sensor its I2C address
-  [change_I2C_addressVL53L0X](./change_I2C_addressVL53L0X/change_I2C_addressVL53L0X.ino) ✅
 - Recommended addresses `0x29` , `0x30` , `0x31`
> Now its your time to work with the 3 of them in same time

