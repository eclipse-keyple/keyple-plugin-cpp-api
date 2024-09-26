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
#include <vector>

#include "keyple/core/plugin/spi/reader/ReaderSpi.hpp"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {

using keyple::core::plugin::spi::reader::ReaderSpi;

/**
 * Plugin (non pool) able to manage a static list of readers.
 *
 * @since 2.0.0
 */
class PluginSpi {
public:
    /**
     *
     */
    virtual ~PluginSpi() = default;

    /**
     * Gets the name of the plugin.
     *
     * @return A not empty string.
     * @since 2.0.0
     */
    virtual const std::string& getName() const = 0;

    /**
     * Enumerates currently available readers.
     *
     * @return A empty Set if no reader is available.
     * @throws PluginIOException If an error occurs while searching readers.
     * @since 2.0.0
     */
    virtual const std::vector<std::shared_ptr<ReaderSpi>>
    searchAvailableReaders() = 0;

    /**
     * Invoked when unregistering the plugin.
     *
     * @since 2.0.0
     */
    virtual void onUnregister() = 0;
};

} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
