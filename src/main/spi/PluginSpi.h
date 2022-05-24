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

#include <list>
#include <memory>
#include <string>

/* Plugin */
#include "ReaderSpi.h"

namespace keyple {
namespace core {
namespace plugin {
namespace spi {

using namespace keyple::core::plugin::spi::reader;

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
    virtual const std::vector<std::shared_ptr<ReaderSpi>> searchAvailableReaders() = 0;

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
