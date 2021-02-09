/*
 *
 */

#ifndef GRAVITY_HEMERABASEINTERFACESPLUGIN_H
#define GRAVITY_HEMERABASEINTERFACESPLUGIN_H

#include <gravityplugin.h>

namespace Hemera {
    class Operation;
}

class HemeraBaseInterfaces;

namespace Gravity {

struct Orbit;

class HemeraBaseInterfacesPlugin : public Gravity::Plugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.ispirata.Hemera.GravityCenter.Plugin")
    Q_CLASSINFO("D-Bus Interface", "com.ispirata.Hemera.GravityCenter.Plugins.HemeraBaseInterfaces")
    Q_INTERFACES(Gravity::Plugin)

    public:
        explicit HemeraBaseInterfacesPlugin();
        virtual ~HemeraBaseInterfacesPlugin();

    protected:
        virtual void unload() override final;
        virtual void load() override final;

    private:
        HemeraBaseInterfaces *m_hemeraBaseInterfaces;
};
}

#endif // GRAVITY_HEMERABASEINTERFACESPLUGIN_H
