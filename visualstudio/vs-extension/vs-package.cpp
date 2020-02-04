//	Copyright (c) 2011-2019 by Artem A. Gevorkyan (gevorkyan.org)
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//	THE SOFTWARE.

#include "command-ids.h"

#include <resources/resource.h>

#include <atlbase.h>
#include <atlcom.h>
#include <dte.h>
#include <vsshell.h>

//using namespace std;
//using namespace placeholders;

namespace micro_profiler
{
	namespace integration
	{
		namespace
		{
			extern const GUID c_guidExperimentalPkg = guidExperimentalPkg;
			extern const GUID c_guidGlobalCmdSet = guidGlobalCmdSet;
		}


		class experimental_package : public CComObjectRoot,
			public CComCoClass<experimental_package, &c_guidExperimentalPkg>,
			public IVsPackage
		{
		public:

		public:
			DECLARE_NO_REGISTRY()
			DECLARE_PROTECT_FINAL_CONSTRUCT()

			BEGIN_COM_MAP(experimental_package)
				COM_INTERFACE_ENTRY(IVsPackage)
			END_COM_MAP()

		private:

			STDMETHODIMP SetSite(IServiceProvider * /*sp*/)
			{
				return S_OK;
			}

			STDMETHODIMP QueryClose(BOOL *can_close)
			{
				*can_close = TRUE;
				return S_OK;
			}

			STDMETHODIMP Close()
			{
				return S_OK;
			}

			STDMETHODIMP GetAutomationObject(LPCOLESTR /*pszPropName*/, IDispatch ** /*ppDisp*/)
			{	return E_NOTIMPL;	}

			STDMETHODIMP CreateTool(REFGUID /*rguidPersistenceSlot*/)
			{	return E_NOTIMPL;	}

			STDMETHODIMP ResetDefaults(VSPKGRESETFLAGS /*grfFlags*/)
			{	return E_NOTIMPL;	}

			STDMETHODIMP GetPropertyPage(REFGUID /*rguidPage*/, VSPROPSHEETPAGE * /*ppage*/)
			{	return E_NOTIMPL;	}

		private:
		};

		OBJECT_ENTRY_AUTO(c_guidExperimentalPkg, experimental_package);
	}
}
