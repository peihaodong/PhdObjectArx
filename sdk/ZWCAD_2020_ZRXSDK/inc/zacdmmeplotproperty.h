

#ifndef ZcDMMEPlotProperty_h
#define ZcDMMEPlotProperty_h

#include "zacarray.h"

class ZcDMMXMLAttribute
{
public:
    ZcDMMXMLAttribute()
    {
        setNull();
    }
    ZcDMMXMLAttribute(const wchar_t *ns, const wchar_t *nsUrl,
        const wchar_t *attName, const wchar_t *attValue)
    {
        setNull();
        SetNamespace(ns);
        SetNamespaceUrl(nsUrl);
        SetAttributeName(attName);
        SetAttributeValue(attValue);
    }
    const ZcDMMXMLAttribute& operator= (const ZcDMMXMLAttribute& src)
    {
        if (this != &src)
        {
            setNull();
            SetNamespace(src.GetNamespace());
            SetNamespaceUrl(src.GetNamespaceUrl());
            SetAttributeName(src.GetAttributeName());
            SetAttributeValue(src.GetAttributeValue());
        }
        return *this;
    }
    ZcDMMXMLAttribute(const ZcDMMXMLAttribute& src)
    {
        *this = src;
    }
    ~ZcDMMXMLAttribute()
    {
        if (NULL != m_namespace)
            delete []m_namespace;
        if (NULL != m_namespaceUrl)
            delete []m_namespaceUrl;
        if (NULL != m_attributeName)
            delete []m_attributeName;
        if (NULL != m_attributeValue)
            delete []m_attributeValue;
    }
    void SetNamespace(const wchar_t* ns)
    {
        delete []m_namespace;
        if (NULL != ns) {
			size_t nSize = ::wcslen(ns) + 1;
            m_namespace = new wchar_t[nSize];
            ::wcscpy_s(m_namespace, nSize, ns);
        } else {
            m_namespace = NULL;
        }
    }
    const wchar_t* GetNamespace() const
    {
        return m_namespace;
    }
    void SetNamespaceUrl(const wchar_t* nsUrl)
    {
        delete []m_namespaceUrl;
        if (NULL != nsUrl) {
			size_t nSize = ::wcslen(nsUrl) + 1;
            m_namespaceUrl = new wchar_t[nSize];
            ::wcscpy_s(m_namespaceUrl, nSize, nsUrl);
        } else {
            m_namespaceUrl = NULL;
        }
    }
    const wchar_t* GetNamespaceUrl() const
    {
        return m_namespaceUrl;
    }
    void SetAttributeName(const wchar_t* attName)
    {
        delete []m_attributeName;
        if (NULL != attName) {
			size_t nSize = ::wcslen(attName) + 1;
            m_attributeName = new wchar_t[nSize];
            ::wcscpy_s(m_attributeName, nSize, attName);
        } else {
            m_attributeName = NULL;
        }
    }
    const wchar_t* GetAttributeName() const
    {
        return m_attributeName;
    }
    void SetAttributeValue(const wchar_t* attValue)
    {
        delete []m_attributeValue;
        if (NULL != attValue) {
			size_t nSize = ::wcslen(attValue) + 1;
            m_attributeValue = new wchar_t[nSize];
            ::wcscpy_s(m_attributeValue, nSize, attValue);
        } else {
            m_attributeValue = NULL;
        }
    }
    const wchar_t* GetAttributeValue() const
    {
        return m_attributeValue;
    }

private:
    wchar_t * m_namespace;
    wchar_t * m_namespaceUrl;
    wchar_t * m_attributeName;
    wchar_t * m_attributeValue;

    void setNull()
    {
        m_namespace = NULL;
        m_namespaceUrl = NULL;
        m_attributeName = NULL;
        m_attributeValue = NULL;
    }
};

typedef std::vector<ZcDMMXMLAttribute> ZcDMMXMLAttributeVec;

class ZcDMMEPlotProperty
{
public:
    ZcDMMEPlotProperty()
    {
        m_name = NULL;
        m_value = NULL;
        m_type = NULL;
        m_units = NULL;
        m_category = NULL;
    }
    ZcDMMEPlotProperty(const wchar_t *name, const wchar_t * value)
    {
        if (NULL != name) {
            m_name = new wchar_t[::wcslen(name) + 1];
            ::wcscpy(m_name, name);
        } else {
            m_name = NULL;
        }

        if (NULL != value) {
            m_value = new wchar_t[::wcslen(value) + 1];
            ::wcscpy(m_value, value);
        } else {
            m_value = NULL;
        }
        m_category = NULL;
        m_type = NULL;
        m_units = NULL;
    }
    ZcDMMEPlotProperty(const ZcDMMEPlotProperty &src)
    {
        m_name = NULL;
        m_value = NULL;
        m_type = NULL;
        m_units = NULL;
        m_category = NULL;
        {*this = src;}
    }
    ~ZcDMMEPlotProperty()
    {
        if (NULL != m_name)
            delete m_name;
        if (NULL != m_value)
            delete m_value;
        if (NULL != m_category)
            delete m_category;
        if (NULL != m_type)
            delete m_type;
        if (NULL != m_units)
            delete m_units;
    }
    void SetType(const wchar_t * type)
    {
        if (m_type)
            delete m_type;
            m_type = NULL;

        if (NULL != type) {
            m_type = new wchar_t[::wcslen(type) + 1];
            ::wcscpy(m_type, type);
        } else {
            m_type = NULL;
        }
    }
    const wchar_t * GetType() const
    {
        return m_type;
    }
    void SetUnits(const wchar_t * units)
    {
        if (m_units)
            delete m_units;
            m_units = NULL;

        if (NULL != units) {
            m_units = new wchar_t[::wcslen(units) + 1];
            ::wcscpy(m_units, units);
        } else {
            m_units = NULL;
        }
    }
    const wchar_t * GetUnits() const
    {
        return m_units;
    }
    void SetCategory(const wchar_t * category)
    {
        if (m_category)
            delete m_category;
            m_category = NULL;

        if (NULL != category) {
            m_category = new wchar_t[::wcslen(category) + 1];
            ::wcscpy(m_category, category);
        } else {
            m_category = NULL;
        }
    }
    const wchar_t * GetCategory() const
    {
        return m_category;
    }
    void SetName(const wchar_t * name)
    {
        if (m_name)
            delete m_name;
            m_name = NULL;

        if (NULL != name) {
            m_name = new wchar_t[::wcslen(name) + 1];
            ::wcscpy(m_name, name);
        } else {
            m_name = NULL;
        }
    }
    const wchar_t * GetName() const
    {
        return m_name;
    }
    void SetValue(const wchar_t * value)
    {
        if (m_value)
            delete m_value;
            m_value = NULL;

        if (NULL != value) {
            m_value = new wchar_t[::wcslen(value) + 1];
            ::wcscpy(m_value, value);
        } else {
            m_value = NULL;
        }
    }
    const wchar_t * GetValue() const
    {
        return m_value;
    }
    ZcDMMEPlotProperty& operator= (const ZcDMMEPlotProperty& src)
    {
        if (this == &src)
            return *this;

        SetName(src.m_name);
        SetValue(src.m_value);
        SetType(src.m_type);
        SetUnits(src.m_units);
        SetCategory(src.m_category);
        m_XMLAttributes = src.m_XMLAttributes;
        return *this;
    }
    void AddXMLAttribute(const ZcDMMXMLAttribute * attrib)
    {
        if(attrib)
            AddXMLAttribute(attrib->GetNamespace(),
                            attrib->GetNamespaceUrl(),
                            attrib->GetAttributeName(),
                            attrib->GetAttributeValue());
    }
    void AddXMLAttribute(const wchar_t *ns, const wchar_t *nsUrl, const wchar_t *attName, const wchar_t *attValue)
    {
        if (NULL != ns && NULL != nsUrl && NULL != attName && NULL != attValue)
            m_XMLAttributes.push_back(ZcDMMXMLAttribute(ns,nsUrl,attName,attValue));
    }
    const ZcDMMXMLAttributeVec& GetXMLAttributes() const
    {
        return m_XMLAttributes;
    }
private:
    wchar_t * m_name;
    wchar_t * m_value;
    wchar_t * m_type;
    wchar_t * m_units;
    wchar_t * m_category;

    ZcDMMXMLAttributeVec    m_XMLAttributes;
};

typedef ZcArray<ZcDMMEPlotProperty> ZcDMMEPlotPropertyVec;

#endif 
