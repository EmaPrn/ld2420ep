import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import binary_sensor
from esphome.const import CONF_ID, DEVICE_CLASS_OCCUPANCY
from .. import ld2420ep_ns, LD2420EPComponent, CONF_LD2420EP_ID

LD2420EPBinarySensor = ld2420ep_ns.class_(
    "LD2420EPBinarySensor", binary_sensor.BinarySensor, cg.Component
)

CONF_HAS_TARGET = "has_target"

CONFIG_SCHEMA = cv.All(
    cv.COMPONENT_SCHEMA.extend(
        {
            cv.GenerateID(): cv.declare_id(LD2420EPBinarySensor),
            cv.GenerateID(CONF_LD2420EP_ID): cv.use_id(LD2420EPComponent),
            cv.Optional(CONF_HAS_TARGET): binary_sensor.binary_sensor_schema(
                device_class=DEVICE_CLASS_OCCUPANCY
            ),
        }
    ),
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    if CONF_HAS_TARGET in config:
        sens = await binary_sensor.new_binary_sensor(config[CONF_HAS_TARGET])
        cg.add(var.set_presence_sensor(sens))
    ld2420ep = await cg.get_variable(config[CONF_LD2420EP_ID])
    cg.add(ld2420ep.register_listener(var))
