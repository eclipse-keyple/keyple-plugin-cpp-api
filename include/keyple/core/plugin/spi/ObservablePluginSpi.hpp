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

#include "keyple/core/plugin/spi/PluginSpi.hpp"
#include "keyple/core/plugin/spi/reader/ReaderSpi.hpp"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {

using keyple::core::plugin::spi::reader::ReaderSpi;

/**
 * Plugin (non pool) able to manage a dynamic list of readers and provide the
 * content on request
 * (for example PC/SC).
 *
 * <p>The production of plugin events (connection/disconnection of readers) is handled by the Keyple
 * Core adapter.
 *
 * @since 2.0.0
 */
class ObservablePluginSpi : public PluginSpi {
public:
    /**
     *
     */
    virtual ~ObservablePluginSpi() = default;

    /**
     * Gets the recommended time cycle in milliseconds to check the list of
     * current readers.
     *
     * @return A positive int
     * @since 2.0.0
     */
    virtual int getMonitoringCycleDuration() const = 0;

    /**
     * Enumerates currently available readers and returns their names as a
     * collection of String.
     *
     * @return An empty list if no reader is available
     * @throws PluginIOException If an error occurs while searching readers.
     * @since 2.0.0
     */
    virtual const std::vector<std::string> searchAvailableReaderNames() = 0;

    /**
     * Searches for the reader whose name is provided and returns its {@link
     * ReaderSpi} if found, null if not.
     *
     * @param readerName The name of reader
     * @return Null if the reader is not found
     * @throws PluginIOException If an error occurs while searching the reader.
     * @since 2.0.0
     */
    virtual std::shared_ptr<ReaderSpi>
    searchReader(const std::string& readerName) = 0;
};

} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
