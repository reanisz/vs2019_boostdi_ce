#include <iostream>
#include <boost/di.hpp>
#include <boost/di/extension/injections/extensible_injector.hpp>

namespace di = boost::di;

struct Hoge {
    Hoge()
        : value(0)
    {
    }

    int value;
};

void dump(const Hoge& hoge){
    std::cout << "(0x" << std::hex << (std::intptr_t)(&hoge) << ") value: " << std::dec << hoge.value << std::endl;
}

void dump(const std::string& name, const Hoge& hoge){
    std::cout << "[" << name << "]";
    dump(hoge);
}

auto model() {
  return di::make_injector(
  );
}

#define DUMP(val) dump(#val, val)

int main(){
    auto injector = model();

    auto& hoge1 = injector.create<Hoge&>();
    hoge1.value = 100;
    auto& hoge2 = injector.create<Hoge&>();

    DUMP(hoge1);
    DUMP(hoge2);

	{
		auto extended_injector = di::make_injector(
			di::extension::make_extensible(injector)
			);
		auto& hoge3 = injector.create<Hoge&>();
		DUMP(hoge3);
	}

    return 0;
}

