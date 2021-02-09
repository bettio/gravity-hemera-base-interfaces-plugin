#include "HemeraBaseInterfaces.h"

#include "ApplianceManifestProducer.h"
#include "hemerabaseinterfacesconfig.h"

#include <GravitySupermassive/GalaxyManager>
#include <GravitySupermassive/StarSequence>

#include <HemeraCore/CommonOperations>
#include <HemeraCore/Literals>

#include <QtCore/QDebug>
#include <QtCore/QLoggingCategory>
#include <QtCore/QSettings>

Q_LOGGING_CATEGORY(LOG_HEMERABASEINTERFACES, "HemeraBaseInterfaces")

HemeraBaseInterfaces::HemeraBaseInterfaces(Gravity::GalaxyManager *manager, QObject *parent)
    : Hemera::AsyncInitObject(parent)
    , m_galaxyManager(manager)
    , m_applianceManifestProducer(new ApplianceManifestProducer(this))
{
}

HemeraBaseInterfaces::~HemeraBaseInterfaces()
{
}

void HemeraBaseInterfaces::initImpl()
{
    if (!m_applianceManifestProducer->isReady()) {
        connect(m_applianceManifestProducer, &ApplianceManifestProducer::ready, this, &HemeraBaseInterfaces::updateApplianceManifest);
    } else {
        updateApplianceManifest();
    }

    setReady();
}

void HemeraBaseInterfaces::updateApplianceManifest()
{
    QSettings manifestSettings(QStringLiteral("/etc/hemera/appliance_manifest"), QSettings::IniFormat);

    if (manifestSettings.status() != QSettings::NoError) {
        qCWarning(LOG_HEMERABASEINTERFACES) << "Error while opening /etc/hemera/appliance_manifest: error: " << manifestSettings.status();
    }

    m_applianceManifestProducer->setApplianceName(manifestSettings.value(QStringLiteral("APPLIANCE_NAME")).toString());
    m_applianceManifestProducer->setApplianceVariant(manifestSettings.value(QStringLiteral("APPLIANCE_VARIANT")).toString());
    m_applianceManifestProducer->setApplianceVersion(manifestSettings.value(QStringLiteral("APPLIANCE_VERSION")).toString());
}
