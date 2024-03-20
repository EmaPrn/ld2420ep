import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import CONF_ID, DEVICE_CLASS_DISTANCE, DEVICE_CLASS_ENERGY, UNIT_CENTIMETER, UNIT_EMPTY
from .. import ld2420ep_ns, LD2420EPComponent, CONF_LD2420EP_ID

LD2420EPSensor = ld2420ep_ns.class_("LD2420EPSensor", sensor.Sensor, cg.Component)

CONF_MOVING_DISTANCE = "moving_distance"

CONFIG_SCHEMA = cv.Schema(
    {
            cv.GenerateID(): cv.declare_id(LD2420EPSensor),
            cv.GenerateID(CONF_LD2420EP_ID): cv.use_id(LD2420EPComponent),
            cv.Optional(CONF_MOVING_DISTANCE): sensor.sensor_schema(
                device_class=DEVICE_CLASS_DISTANCE, unit_of_measurement=UNIT_CENTIMETER
            ),
            cv.Optional(f"gate_0_energy"): sensor.sensor_schema(
                    device_class=DEVICE_CLASS_ENERGY, unit_of_measurement=UNIT_EMPTY
            ),        
    }
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    if CONF_MOVING_DISTANCE in config:
        sens = await sensor.new_sensor(config[CONF_MOVING_DISTANCE])
        cg.add(var.set_distance_sensor(sens))
    for x in range(16):
        if gate_energy_conf := config.get(f"gate_{x}_energy"):
            sens = await sensor.new_sensor(gate_energy_conf)
            cg.add(var.set_energy_sensor(x, sens))

    ld2420ep = await cg.get_variable(config[CONF_LD2420EP_ID])
    cg.add(ld2420ep.register_listener(var))
