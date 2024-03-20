#include "ld2420ep_sensor.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

namespace esphome
{
  namespace ld2420ep
  {

    static const char *const TAG = "LD2420EP.sensor";

    void LD2420EPSensor::dump_config()
    {
      ESP_LOGCONFIG(TAG, "LD2420EP Sensor:");
      LOG_SENSOR("  ", "Distance", this->distance_sensor_);
      for (size_t x = 0; x < 16; x++)
      {
        LOG_SENSOR("  ", "Energy " + char(x), this->energy_sensors_[x]);
      }
    }

  } // namespace ld2420ep
} // namespace esphome
