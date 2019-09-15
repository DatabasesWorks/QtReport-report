#ifndef QREPORTUNDOCOMMANDS_H
#define QREPORTUNDOCOMMANDS_H

#include "qtreportglobal.h"
#include <QUndoCommand>
#include <QVariant>

LEAF_BEGIN_NAMESPACE

class Report;
class DocumentDesigner;
class UndoCommandPrivate;
class DataConnection;
class DataTable;
class Band;
class Parametere;
class WidgetBase;
class Variable;
class SeriazbleObject;
class WidgetAttributes;
class UndoCommand : public QUndoCommand
{

private:
    UndoCommandPrivate *d_ptr;
    Q_DECLARE_PRIVATE(UndoCommand)

public:

    UndoCommand();
    UndoCommand(DocumentDesigner *designer, Report *report);

    virtual void undo();
    virtual void redo();

    void setReady();

    DocumentDesigner *designer() const;
    Report *report() const;

    void setDesigner(DocumentDesigner *designer);
    void setReport(Report *report);

    void setOldState(QString oldState);
    void setNewState(QString newState);

    void setOldName(QString oldName);
    void setNewName(QString newName);

};

class WidgetPropertyUndoCommand : public UndoCommand
{
    QList<WidgetBase*> _widgets;
    WidgetAttributes *_old;
    WidgetAttributes *_new;

    struct AttributeChange
    {
        QString name;
        QVariant oldValue;
        QVariant newValue;
    };
    QList<AttributeChange*> changes;
    void setOld(QString name, QVariant v);
    void setNew(QString name, QVariant v);
};

class ObjectPropertyUndoCommand : public UndoCommand
{
    SeriazbleObject *_object;

public:
    ObjectPropertyUndoCommand(SeriazbleObject *o, DocumentDesigner *designer, Report *report);

    SeriazbleObject *object() const;
    void setObject(SeriazbleObject *object);

    void setOldState();
};

#define UNDO_COMMAND_DECL(TYPE) \
    class TYPE##UndoCommand : public UndoCommand \
{ \
    TYPE *obj; \
public: \
    TYPE##UndoCommand(TYPE *object, DocumentDesigner *designer, Report *report); \
public: \
    void undo() Q_DECL_OVERRIDE; \
    void redo() Q_DECL_OVERRIDE; \
};

UNDO_COMMAND_DECL(DataConnection)
UNDO_COMMAND_DECL(DataTable)
UNDO_COMMAND_DECL(Band)
UNDO_COMMAND_DECL(Parametere)
UNDO_COMMAND_DECL(WidgetBase)
UNDO_COMMAND_DECL(Variable)

LEAF_END_NAMESPACE

#endif // QREPORTUNDOCOMMANDS_H
