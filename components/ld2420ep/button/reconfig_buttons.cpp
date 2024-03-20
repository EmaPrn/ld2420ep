#include "reconfig_buttons.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

static const char *const TAG = "LD2420EP.button";

namespace esphome
{
    namespace ld2420ep
    {

        void LD2420EPApplyConfigButton::press_action() { this->parent_->apply_config_action(); }
        void LD2420EPRevertConfigButton::press_action() { this->parent_->revert_config_action(); }
        void LD2420EPRestartModuleButton::press_action() { this->parent_->restart_module_action(); }
        void LD2420EPFactoryResetButton::press_action() { this->parent_->factory_reset_action(); }

    } // namespace ld2420ep
} // namespace esphome
