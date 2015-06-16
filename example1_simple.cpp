#include "burst/html.hpp"
using namespace myun2::burst;

struct my_document : html_generator<5>
{
	void render_body_content() {
		tag("h1", "Hello World");
	}
};

int main(int argc, char *argv[])
{
	my_document().render();
	return 0;
}
