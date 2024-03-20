import esphome.codegen as cg
from esphome.components import select
import esphome.config_validation as cv
from esphome.const import ENTITY_CATEGORY_CONFIG
from .. import CONF_LD2420EP_ID, LD2420EPComponent, ld2420ep_ns

CONF_OPERATING_MODE = "operating_mode"
CONF_SELECTS = [
    "Normal",
    "Calibrate",
    "Simple",
]

LD2420EPSelect = ld2420ep_ns.class_("LD2420EPSelect", cg.Component)

CONFIG_SCHEMA = {
    cv.GenerateID(CONF_LD2420EP_ID): cv.use_id(LD2420EPComponent),
    cv.Required(CONF_OPERATING_MODE): select.select_schema(
        LD2420EPSelect,
        entity_category=ENTITY_CATEGORY_CONFIG,
    ),
}


async def to_code(config):
    LD2420EP_component = await cg.get_variable(config[CONF_LD2420EP_ID])
    if operating_mode_config := config.get(CONF_OPERATING_MODE):
        sel = await select.new_select(
            operating_mode_config,
            options=[CONF_SELECTS],
        )
        await cg.register_parented(sel, config[CONF_LD2420EP_ID])
        cg.add(LD2420EP_component.set_operating_mode_select(sel))
