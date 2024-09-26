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

#include <memory>
#include <string>

#include "keyple/core/plugin/spi/PluginSpi.hpp"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {

/**
 * Factory of {@link PluginSpi}
 *
 * @since 2.0.0
 */
class PluginFactorySpi {
public:
    /**
     *
     */
    virtual ~PluginFactorySpi() = default;

    /**
     * Gets the plugin's API version used at compile time
     *
     * @return A not empty String
     * @since 2.0.0
     */
    virtual const std::string getPluginApiVersion() const = 0;

    /**
     * Gets the common's API version used at compile time
     *
     * @return A not empty String
     * @since 2.0.0
     */
    virtual const std::string getCommonApiVersion() const = 0;

    /**
     * Retrieves the name of the plugin that will be instantiated by this
     * factory (can be static or dynamic)
     *
     * @return A not empty String
     * @since 2.0.0
     */
    virtual const std::string& getPluginName() const = 0;

    /**
     * Retrieves an instance of a plugin SPI (can be a singleton or not)
     *
     * @return A not null reference
     * @since 2.0.0
     */
    virtual std::shared_ptr<PluginSpi> getPlugin() = 0;
};

} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
