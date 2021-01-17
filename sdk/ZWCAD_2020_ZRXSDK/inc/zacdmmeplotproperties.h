
#ifndef ZcDMMEPlotProperties_h
#define ZcDMMEPlotProperties_h

#include "zacdmmeplotproperty.h"
#include "zacdmmutils.h"

class ZcDMMEPlotProperties
{
public:
    ZcDMMEPlotProperties()
        : m_id(NULL)
    {

    }
    ZcDMMEPlotProperties(const ZcDMMEPlotProperties &src)
        : m_id(NULL)
    {
        *this = src;
    }
    ~ZcDMMEPlotProperties()
    {
        m_properties.removeAll();
        m_refs.removeAll();
        if (NULL != m_id)
            delete m_id;
    }
    void AddProperty(const ZcDMMEPlotProperty * property)
    {
        if (NULL == property)
            return;
        m_properties.append(*property);
    }
    void AddProperty(wchar_t * name, wchar_t *value)
    {
        ZcDMMEPlotProperty newProp(name, value);
        m_properties.append(newProp);
    }
    const ZcDMMEPlotPropertyVec& GetProperties() const
    {
        return m_properties;
    }
    const ZcDMMEPlotProperty * GetProperty(unsigned long index) const
    {
        if (m_properties.length() <= (int)index)
            return NULL;
        return &m_properties[index];
    }
    void SetId(const wchar_t * id)
    {
        if (NULL != m_id)
            delete m_id;
        if (NULL != id) {
			size_t nSize = ::wcslen(id) + 1;
            m_id = new wchar_t[nSize];
            ::wcscpy_s(m_id, nSize, id);
        } else
            m_id = NULL;
    }
    const wchar_t * GetId() const
    {
        return m_id;
    }
    void SetRefs(const ZcDMMStringVec& refs)
    {
		m_refs.removeAll();
		for (int i = 0; i < refs.length(); i++)
			m_refs.append(refs.at(i));
    }
    const ZcDMMStringVec * GetRefs() const
    {
        return &m_refs;
    }
    ZcDMMEPlotProperties& operator= (const ZcDMMEPlotProperties &src)
    {
        if (this == &src)
            return *this;

		m_properties.removeAll();
		for (int i = 0; i < src.m_properties.length(); i++)
			m_properties.append(src.m_properties.at(i));
        SetId(src.m_id);
        SetRefs(src.m_refs);
        return *this;
    }

private:

    ZcDMMEPlotPropertyVec m_properties;
    wchar_t * m_id;
    ZcDMMStringVec m_refs;
};

#endif 
