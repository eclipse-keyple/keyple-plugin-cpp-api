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
#include "keyple/core/plugin/spi/PoolPluginSpi.hpp"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {

/**
 * Factory of {@link PoolPluginSpi}
 *
 * @since 2.0.0
 */
class PoolPluginFactorySpi {
public:
    /**
     *
     */
    virtual ~PoolPluginFactorySpi() = default;

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
     * Retrieves the name of the pool plugin that will be instantiated by this
     * factory (can be static or dynamic)
     *
     * @return A not empty String
     * @since 2.0.0
     */
    virtual const std::string& getPoolPluginName() const = 0;

    /**
     * Retrieves an instance of a pool plugin SPI (can be a singleton or not)
     *
     * @return A not null reference
     * @since 2.0.0
     */
    virtual std::shared_ptr<PoolPluginSpi> getPoolPlugin() = 0;
};

} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
