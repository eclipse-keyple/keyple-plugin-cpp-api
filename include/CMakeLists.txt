# *****************************************************************************
# Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/     *
#                                                                             *
# This program and the accompanying materials are made available under the    *
# terms of the MIT License which is available at                              *
# https://opensource.org/licenses/MIT.                                        *
#                                                                             *
# SPDX-License-Identifier: MIT                                                *
# *****************************************************************************/

SET(LIBRARY_NAME keypleplugin)

# Include deps
INCLUDE("CMakeLists.txt.keyple-util")

ADD_LIBRARY(

    ${LIBRARY_NAME}

    INTERFACE
)

ADD_LIBRARY(

    Keyple::Plugin

    ALIAS

    ${LIBRARY_NAME}
)

TARGET_INCLUDE_DIRECTORIES(

    ${LIBRARY_NAME}

    INTERFACE

    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
)

TARGET_LINK_LIBRARIES(

    ${LIBRARY_NAME}

    INTERFACE

    Keyple::Util
)
