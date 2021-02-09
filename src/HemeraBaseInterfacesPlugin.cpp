/*
 *
 */

#include "HemeraBaseInterfacesPlugin.h"

#include "HemeraBaseInterfaces.h"

#include <QtCore/QLoggingCategory>

#include <HemeraCore/CommonOperations>

#include <GravitySupermassive/GalaxyManager>

Q_LOGGING_CATEGORY(LOG_HEMERABASEINTERFACESPLUGIN, "HemeraBaseInterfacesPlugin")

using namespace Gravity;

HemeraBaseInterfacesPlugin::HemeraBaseInterfacesPlugin()
    : Gravity::Plugin()
{
    setName(QStringLiteral("Hemera HemeraBaseInterfaces"));
}

HemeraBaseInterfacesPlugin::~HemeraBaseInterfacesPlugin()
{
}

void HemeraBaseInterfacesPlugin::unload()
{
    qCDebug(LOG_HEMERABASEINTERFACESPLUGIN) << "HemeraBaseInterfaces plugin unloaded";
    setUnloaded();
}

void HemeraBaseInterfacesPlugin::load()
{
    m_hemeraBaseInterfaces = new HemeraBaseInterfaces(galaxyManager());

    connect(m_hemeraBaseInterfaces->init(), &Hemera::Operation::finished, this, [this] (Hemera::Operation *op){
        if (op->isError()) {
            qCDebug(LOG_HEMERABASEINTERFACESPLUGIN) << "Error in loading HemeraBaseInterfaces plugin: " << op->errorName() << op->errorMessage();
        } else {
            qCDebug(LOG_HEMERABASEINTERFACESPLUGIN) << "HemeraBaseInterfaces mode plugin loaded";
            setLoaded();
        }
    });
}

