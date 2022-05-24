/**************************************************************************************************
 * Copyright (c) 2021 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * See the NOTICE file(s) distributed with this work for additional information regarding         *
 * copyright ownership.                                                                           *
 *                                                                                                *
 * This program and the accompanying materials are made available under the terms of the Eclipse  *
 * Public License 2.0 which is available at http://www.eclipse.org/legal/epl-2.0                  *
 *                                                                                                *
 * SPDX-License-Identifier: EPL-2.0                                                               *
 **************************************************************************************************/

#pragma once

#include <string.h>

/* Plugin */
#include "ReaderSpi.h"
#include "PluginSpi.h"
#include "PoolPluginSpi.h"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {

/**
 * Plugin able to manage a dynamic list of readers based on a allocation/deallocation mechanism (for
 * example HSM).
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
    virtual const std::string& getName() const  = 0;

    /**
     * Gets a list of group references that will be used as an argument to {@link
     * #allocateReader(String)}.
     *
     * <p>A group reference can represent a family of Reader with all the same characteristics (for
     * example SAM with identical key sets).
     *
     * @return An empty Set if there is no group reference
     * @throw PluginIOException If an error occurs
     * @since 2.0.0
     */
    virtual const std::vector<std::string> getReaderGroupReferences() const = 0;

    /**
     * Obtains an available reader resource and makes it exclusive to the caller until the
     * releaseReader method is invoked.
     *
     * <p>The allocated reader belongs to the group targeted with the provided group reference.
     *
     * @param readerGroupReference The reader group reference (optional)
     * @return A not null reference
     * @throw PluginIOException If an error occurs
     * @since 2.0.0
     */
    virtual std::shared_ptr<ReaderSpi> allocateReader(const std::string& readerGroupReference) = 0;

    /**
     * Releases the reader previously allocated with {@link #allocateReader(String)} and whose
     * reference is provided.
     *
     * <p>This method must be invoked as soon as the reader is no longer needed by the caller of
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

}
}
}
}
