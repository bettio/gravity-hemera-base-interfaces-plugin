set(GravityHemeraBaseInterfacesPlugin_SRCS
    HemeraBaseInterfacesPlugin.cpp
    HemeraBaseInterfaces.cpp
)

hyperspace_add_qt5_producer(GravityHemeraBaseInterfacesPlugin_SRCS ${CMAKE_SOURCE_DIR}/share/com.ispirata.Hemera.ApplianceManifest.json
                            ApplianceManifestProducer ApplianceManifestProducer)

# final lib
add_library(gravity-center-plugin-hemera-base-interfaces SHARED ${GravityHemeraBaseInterfacesPlugin_SRCS})

target_link_libraries(gravity-center-plugin-hemera-base-interfaces
                      Gravity::Supermassive
                      HemeraQt5SDK::Core
                      HyperspaceQt5::Core HyperspaceQt5::ProducerConsumer
                      Qt5::Core Qt5::DBus)

# Install phase
install(TARGETS gravity-center-plugin-hemera-base-interfaces
        RUNTIME DESTINATION "${GRAVITY_PLUGINS_DIR}" COMPONENT bin
        LIBRARY DESTINATION "${GRAVITY_PLUGINS_DIR}" COMPONENT shlib
        ARCHIVE DESTINATION "${GRAVITY_PLUGINS_DIR}" COMPONENT shlib
        COMPONENT gravity-hemera-base-interfaces)
