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
#include <vector>

#include "keyple/core/plugin/spi/reader/ReaderSpi.hpp"

namespace keyple {
namespace core {
namespace plugin {

using keyple::core::plugin::spi::reader::ReaderSpi;

/**
 * API associated to a keyple::core::plugin::spi::AutonomousObservablePluginSpi.
 *
 * @since 2.0.0
 */
class AutonomousObservablePluginApi {
public:
    /**
     *
     */
    virtual ~AutonomousObservablePluginApi() = default;

    /**
     * Must be invoked when one or more readers are connected to the system.
     *
     * @param readers the readers connected
     * @throw IllegalArgumentException If the Set provided as argument is null
     * or empty
     * @since 2.0.0
     */
    virtual void
    onReaderConnected(const std::vector<std::shared_ptr<ReaderSpi>>& readers)
        = 0;

    /**
     * Must be invoked when one or more readers are disconnected from the
     * system.
     *
     * @param readerNames the readers names disconnected
     * @throw IllegalArgumentException If the Set provided as argument is null
     * or empty
     * @since 2.0.0
     */
    virtual void
    onReaderDisconnected(const std::vector<std::string>& readerNames)
        = 0;
};

} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
