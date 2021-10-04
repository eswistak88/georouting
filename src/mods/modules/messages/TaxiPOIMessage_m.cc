//
// Generated file, do not edit! Created by nedtool 5.6 from mods/modules/messages/TaxiPOIMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "TaxiPOIMessage_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace veins {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(TaxiPOIMessage)

TaxiPOIMessage::TaxiPOIMessage(const char *name, short kind) : ::veins::DemoServiceAdvertisment(name,kind)
{
    this->MsgID = 0;
    this->TargetPOI = 0;
}

TaxiPOIMessage::TaxiPOIMessage(const TaxiPOIMessage& other) : ::veins::DemoServiceAdvertisment(other)
{
    copy(other);
}

TaxiPOIMessage::~TaxiPOIMessage()
{
}

TaxiPOIMessage& TaxiPOIMessage::operator=(const TaxiPOIMessage& other)
{
    if (this==&other) return *this;
    ::veins::DemoServiceAdvertisment::operator=(other);
    copy(other);
    return *this;
}

void TaxiPOIMessage::copy(const TaxiPOIMessage& other)
{
    this->MsgID = other.MsgID;
    this->Sender = other.Sender;
    this->SenderPos = other.SenderPos;
    this->TargetPOI = other.TargetPOI;
}

void TaxiPOIMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::DemoServiceAdvertisment::parsimPack(b);
    doParsimPacking(b,this->MsgID);
    doParsimPacking(b,this->Sender);
    doParsimPacking(b,this->SenderPos);
    doParsimPacking(b,this->TargetPOI);
}

void TaxiPOIMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::DemoServiceAdvertisment::parsimUnpack(b);
    doParsimUnpacking(b,this->MsgID);
    doParsimUnpacking(b,this->Sender);
    doParsimUnpacking(b,this->SenderPos);
    doParsimUnpacking(b,this->TargetPOI);
}

int TaxiPOIMessage::getMsgID() const
{
    return this->MsgID;
}

void TaxiPOIMessage::setMsgID(int MsgID)
{
    this->MsgID = MsgID;
}

LAddress::L2Type& TaxiPOIMessage::getSender()
{
    return this->Sender;
}

void TaxiPOIMessage::setSender(const LAddress::L2Type& Sender)
{
    this->Sender = Sender;
}

Coord& TaxiPOIMessage::getSenderPos()
{
    return this->SenderPos;
}

void TaxiPOIMessage::setSenderPos(const Coord& SenderPos)
{
    this->SenderPos = SenderPos;
}

int TaxiPOIMessage::getTargetPOI() const
{
    return this->TargetPOI;
}

void TaxiPOIMessage::setTargetPOI(int TargetPOI)
{
    this->TargetPOI = TargetPOI;
}

class TaxiPOIMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TaxiPOIMessageDescriptor();
    virtual ~TaxiPOIMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(TaxiPOIMessageDescriptor)

TaxiPOIMessageDescriptor::TaxiPOIMessageDescriptor() : omnetpp::cClassDescriptor("veins::TaxiPOIMessage", "veins::DemoServiceAdvertisment")
{
    propertynames = nullptr;
}

TaxiPOIMessageDescriptor::~TaxiPOIMessageDescriptor()
{
    delete[] propertynames;
}

bool TaxiPOIMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TaxiPOIMessage *>(obj)!=nullptr;
}

const char **TaxiPOIMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TaxiPOIMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TaxiPOIMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int TaxiPOIMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *TaxiPOIMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "MsgID",
        "Sender",
        "SenderPos",
        "TargetPOI",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int TaxiPOIMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='M' && strcmp(fieldName, "MsgID")==0) return base+0;
    if (fieldName[0]=='S' && strcmp(fieldName, "Sender")==0) return base+1;
    if (fieldName[0]=='S' && strcmp(fieldName, "SenderPos")==0) return base+2;
    if (fieldName[0]=='T' && strcmp(fieldName, "TargetPOI")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TaxiPOIMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "LAddress::L2Type",
        "Coord",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **TaxiPOIMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TaxiPOIMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TaxiPOIMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TaxiPOIMessage *pp = (TaxiPOIMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TaxiPOIMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TaxiPOIMessage *pp = (TaxiPOIMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TaxiPOIMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TaxiPOIMessage *pp = (TaxiPOIMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMsgID());
        case 1: {std::stringstream out; out << pp->getSender(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSenderPos(); return out.str();}
        case 3: return long2string(pp->getTargetPOI());
        default: return "";
    }
}

bool TaxiPOIMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TaxiPOIMessage *pp = (TaxiPOIMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setMsgID(string2long(value)); return true;
        case 3: pp->setTargetPOI(string2long(value)); return true;
        default: return false;
    }
}

const char *TaxiPOIMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(LAddress::L2Type));
        case 2: return omnetpp::opp_typename(typeid(Coord));
        default: return nullptr;
    };
}

void *TaxiPOIMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TaxiPOIMessage *pp = (TaxiPOIMessage *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getSender()); break;
        case 2: return (void *)(&pp->getSenderPos()); break;
        default: return nullptr;
    }
}

} // namespace veins

