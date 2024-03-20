import esphome.codegen as cg
from esphome.components import text_sensor
import esphome.config_validation as cv
from esphome.const import (
    CONF_ID,
    ENTITY_CATEGORY_DIAGNOSTIC,
    ICON_CHIP,
)

from .. import ld2420ep_ns, LD2420EPComponent, CONF_LD2420EP_ID

LD2420EPTextSensor = ld2420ep_ns.class_(
    "LD2420EPTextSensor", text_sensor.TextSensor, cg.Component
)

CONF_FW_VERSION = "fw_version"

CONFIG_SCHEMA = cv.All(
    cv.COMPONENT_SCHEMA.extend(
        {
            cv.GenerateID(): cv.declare_id(LD2420EPTextSensor),
            cv.GenerateID(CONF_LD2420EP_ID): cv.use_id(LD2420EPComponent),
            cv.Optional(CONF_FW_VERSION): text_sensor.text_sensor_schema(
                entity_category=ENTITY_CATEGORY_DIAGNOSTIC, icon=ICON_CHIP
            ),
        }
    ),
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    if CONF_FW_VERSION in config:
        sens = await text_sensor.new_text_sensor(config[CONF_FW_VERSION])
        cg.add(var.set_fw_version_text_sensor(sens))
    ld2420ep = await cg.get_variable(config[CONF_LD2420EP_ID])
    cg.add(ld2420ep.register_listener(var))
