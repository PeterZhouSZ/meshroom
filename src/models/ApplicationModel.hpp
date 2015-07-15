#pragma once

#include <QObject>

namespace mockup
{

class Application;  // forward declaration
class ProjectModel; // forward declaration

class ApplicationModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> projects READ projects WRITE setProjects NOTIFY projectsChanged)
    Q_PROPERTY(QList<QObject*> logs READ logs WRITE setLogs NOTIFY logsChanged)

public:
    ApplicationModel(Application& app);
    ~ApplicationModel() = default;

public slots:
    const QList<QObject*>& projects() const;
    void setProjects(const QList<QObject*>& projects);
    const QList<QObject*>& logs() const;
    void addLog(QObject* log);
    void setLogs(const QList<QObject*>& logs);
    QObject* addNewProject();
    QObject* addExistingProject(const QUrl& url);
    void removeProject(QObject* projectModel);

signals:
    void projectsChanged();
    void logsChanged();

private:
    void exposeToQML();

private:
    QList<QObject*> _projects;
    QList<QObject*> _logs;
    Application& _application;
};

} // namespaces
