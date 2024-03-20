import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart
from esphome.const import CONF_ID

CODEOWNERS = ["@descipher"]

DEPENDENCIES = ["uart"]

MULTI_CONF = True

ld2420ep_ns = cg.esphome_ns.namespace("ld2420ep")
LD2420EPComponent = ld2420ep_ns.class_("LD2420EPComponent", cg.Component, uart.UARTDevice)

CONF_LD2420EP_ID = "ld2420ep_id"

CONFIG_SCHEMA = cv.All(
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(LD2420EPComponent),
        }
    )
    .extend(uart.UART_DEVICE_SCHEMA)
    .extend(cv.COMPONENT_SCHEMA)
)

FINAL_VALIDATE_SCHEMA = uart.final_validate_device_schema(
    "ld2420ep_uart",
    require_tx=True,
    require_rx=True,
    parity="NONE",
    stop_bits=1,
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await uart.register_uart_device(var, config)
