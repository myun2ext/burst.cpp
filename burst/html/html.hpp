#ifndef __MYUN2_GITHUB_COM__BURST__HTML__HTML_HPP__
#define __MYUN2_GITHUB_COM__BURST__HTML__HTML_HPP__

#include "base.hpp"
#include "tag.hpp"
#include "head.hpp"
#include "doctype.hpp"

namespace myun2
{
	namespace burst
	{
		namespace html
		{
			struct body : html::tag_generator {
				body(FILE* f_in = NULL) : html::tag_generator("body", f_in){}
			};
		}

		template <unsigned char _HtmlVersion>
		struct html_generator : html::tag_generator
		{
			html_generator(FILE* f_in = NULL) : html::tag_generator("html", f_in){}

			virtual void render_head(){ html::head().render(f); }
			virtual void render_body(){ html::body().render(f); }
			virtual void render_content() {
				render_head();
				render_body();
			}

			void start() {
				html::doctype_generator<_HtmlVersion>(f).generate();
				tag_generator::start();
			}
		};
	}
}

#endif//__MYUN2_GITHUB_COM__BURST__HTML__HTML_HPP__
