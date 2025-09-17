/******************************************************************************
 * Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT.                                       *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#pragma once

#include <list>
#include <memory>
#include <string>

#include "keyple/core/plugin/AutonomousObservablePluginApi.hpp"
#include "keyple/core/plugin/spi/PluginSpi.hpp"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {

using keyple::core::plugin::AutonomousObservablePluginApi;

/**
 * Plugin (non pool) having autonomous capabilities to observe reader
 * connections and disconnections.
 *
 * <p>Plugin events are produced by the plugin itself.
 *
 * @since 2.0.0
 */
class AutonomousObservablePluginSpi : public PluginSpi {
public:
    /**
     *
     */
    virtual ~AutonomousObservablePluginSpi() = default;

    /**
     * Connects the associated Keyple Core {@link AutonomousObservablePluginApi}
     * API.
     *
     * /!\ C++: cannot use a shared_ptr here as this function is called from constructors
     *
     * @param autonomousObservablePluginApi The API to connect.
     * @since 2.0.0
     * @deprecated Use setCallback(AutonomousObservablePluginApi) instead.
     */
    virtual void
    connect(AutonomousObservablePluginApi* autonomousObservablePluginApi)
        = 0;

    /**
     * Sets the asynchronous callback that will be called when a reader is
     * connected or disconnected.
     *
     * @param callback The asynchronous callback to be called.
     * @since 2.2.0
     */
    virtual void setCallback(AutonomousObservablePluginApi* callback) = 0;
};

} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
