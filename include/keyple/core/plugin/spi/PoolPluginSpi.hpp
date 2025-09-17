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

#include "keyple/core/plugin/spi/PluginSpi.hpp"
#include "keyple/core/plugin/spi/reader/PoolReaderSpi.hpp"
#include "keyple/core/plugin/spi/reader/ReaderSpi.hpp"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {

using keyple::core::plugin::spi::reader::PoolReaderSpi;
using keyple::core::plugin::spi::reader::ReaderSpi;

/**
 * lugin able to manage a dynamic list of readers based on an allocation/de-allocation mechanism
 * (for example HSM).
 *
 * @since 2.0.0
 */
class PoolPluginSpi {
public:
    /**
     *
     */
    virtual ~PoolPluginSpi() = default;

    /**
     * Gets the name of the pool plugin.
     *
     * @return A not empty string.
     * @since 2.0.0
     */
    virtual const std::string& getName() const = 0;

    /**
     * Gets a list of group references that will be used as an argument to
     * {@link #allocateReader(String)}.
     *
     * <p>A group reference can represent a family of Reader with all the same
     * characteristics (for example SAM with identical key sets).
     *
     * @return An empty Set if there is no group reference
     * @throw PluginIOException If an error occurs
     * @since 2.0.0
     */
    virtual const std::vector<std::string> getReaderGroupReferences() const = 0;

    /**
     * Obtains an available reader resource and makes it exclusive to the caller
     * until the releaseReader method is invoked.
     *
     * <p>The allocated reader belongs to the group targeted with the provided
     * group reference.
     *
     * @param readerGroupReference The reader group reference (optional).
     * @return A not null reference.
     * @throw PluginIOException If an error occurs.
     * @since 2.0.0
     */
    virtual std::shared_ptr<PoolReaderSpi>
    allocateReader(const std::string& readerGroupReference) = 0;

    /**
     * Releases the reader previously allocated with {@link
     * #allocateReader(String)} and whose reference is provided.
     *
     * <p>This method must be invoked as soon as the reader is no longer needed
     * by the caller of
     * {@link #allocateReader(String)} in order to free the resource.
     *
     * @param readerSpi The reader to deallocate
     * @throw PluginIOException If an error occurs
     * @since 2.0.0
     */
    virtual void releaseReader(std::shared_ptr<ReaderSpi> readerSpi) = 0;

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
