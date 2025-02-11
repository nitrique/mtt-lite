file_path = "./hex/eeprom-355148.hex"

with open(file_path, "rb") as f:
    binary_data_2 = f.read()

arduino_array = ", ".join(f"0x{b:02X}" for b in binary_data_2)

arduino_code = f"""
const byte eeprom_data[] = {{
    {arduino_array}
}};

const size_t eeprom_size = sizeof(eeprom_data);
"""

print(arduino_code)