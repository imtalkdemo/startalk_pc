﻿#ifndef GLOBAL_MANAGER_H
#define GLOBAL_MANAGER_H

#include "../UICom/Config/configobject.h"
#include "PlugManager.h"
#include "StyleManager.h"
#include "../QtUtil/lib/ini/ConfigLoader.h"
#include "../Platform/AppSetting.h"

class GlobalManager : public ConfigObject
{
    Q_OBJECT
public:
    static GlobalManager *instance();
    static QJsonDocument loadJsonConfig(const QString &path);

    QObject *getPluginInstanceQt(const QString &key);
    bool UnloadPluginQt(const QString &key);
    std::shared_ptr<QMap<QString, QObject *> > getAllPluginInstanceQt();
    void init();
    void InitPluginManager();
    void setStyleSheetAll();
    void setStylesForApp();
    void setStyleSheetForPlugin(const QString& plgName);

    void initThemeConfig();

public slots:
    void saveSysConfig();

private:
    GlobalManager();

Q_SIGNALS:
    void sgMousePressGlobalPos(const QPoint & pos);

private:
    QString            _ConfigDataDir;
    PlugManager        _pluginManager;
    StyleManager       _pstyleSheetManager;

private:
    QTalk::ConfigLoader *_pSystemConfig;
    int _theme = 1;
    std::string _font;
    int _font_level{};

public:
#ifdef _STARTALK
    bool _check_updater = true;
#endif
    int  _updater_version = 0;
};

#endif // GLOBAL_MANAGER_H
