#ifndef HEMERABASEINTERFACES_H
#define HEMERABASEINTERFACES_H

#include <HemeraCore/AsyncInitObject>

namespace Gravity {
class GalaxyManager;
}

class ApplianceManifestProducer;

class HemeraBaseInterfaces : public Hemera::AsyncInitObject
{
    Q_OBJECT
    Q_DISABLE_COPY(HemeraBaseInterfaces)

    public:
        explicit HemeraBaseInterfaces(Gravity::GalaxyManager *manager, QObject *parent = nullptr);
        virtual ~HemeraBaseInterfaces();

        virtual bool isValid() { return true; }

    protected:
        virtual void initImpl() override final;

    private slots:
        void updateApplianceManifest();

    private:
        Gravity::GalaxyManager *m_galaxyManager;
        ApplianceManifestProducer *m_applianceManifestProducer;
};

#endif
