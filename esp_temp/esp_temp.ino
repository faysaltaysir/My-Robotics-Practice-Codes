#include <esp_temp_sensor.h>

void app_main() {
    float temperature = esp_temperature_sensor_get_val(ESP_TEMP_SENSOR_CORE);
    printf("Temperature: %.2f°C\n", temperature);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
