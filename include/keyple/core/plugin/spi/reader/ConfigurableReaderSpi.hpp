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

#include <string>

#include "keyple/core/plugin/spi/reader/ReaderSpi.hpp"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {
namespace reader {

using keyple::core::plugin::spi::reader::ReaderSpi;

/**
 * Reader able to manage multiple protocols and which allows the configuration
 * of the protocol to use.
 *
 * @since 2.0.0
 */
class ConfigurableReaderSpi : public virtual ReaderSpi {
public:
    /**
     *
     */
    virtual ~ConfigurableReaderSpi() = default;

    /**
     * Indicates if the provided reader protocol is supported by the reader.
     *
     * <p>Using this method allows to invoke the activateProtocol() method only
     * if the protocol is supported.
     *
     * @param readerProtocol The reader protocol.
     * @return True if the protocol is supported, false if not.
     * @since 2.0.0
     */
    virtual bool
    isProtocolSupported(const std::string& readerProtocol) const = 0;

    /**
     * Activates a specific protocol in order to make the reader able to
     * communicate with the cards using this protocol.
     *
     * @param readerProtocol The reader specific protocol to activate.
     * @since 2.0.0
     */
    virtual void activateProtocol(const std::string& readerProtocol) = 0;

    /**
     * Deactivates a specific protocol so that the reader ignores cards using
     * this protocol.
     *
     * @param readerProtocol The reader specific protocol to deactivate.
     * @since 2.0.0
     */
    virtual void deactivateProtocol(const std::string& readerProtocol) = 0;

    /**
     * Tells if the current card communicates with the provided protocol.
     *
     * @param readerProtocol The reader protocol to check.
     * @return True if the current protocol corresponds to the one provided,
     * false if not.
     * @since 2.0.0
     */
    virtual bool isCurrentProtocol(const std::string& readerProtocol) const = 0;
};

} /* namespace reader */
} /* namespace spi */
} /* namespace plugin */
} /* namespace core */
} /* namespace keyple */
