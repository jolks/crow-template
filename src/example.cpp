#include <sstream>
#include <string>

#include "crow.h"
#include "json.h"

using namespace std;

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/about")
    ([](){
        return "About Crow example.";
    });

    // simple json response
    CROW_ROUTE(app, "/json")
    ([]{
        crow::json::wvalue x;
        x["message"] = "Hello, World!";
        return x;
    });

    // argument
    CROW_ROUTE(app,"/hello/<int>")
    ([](int count){
        if (count > 100)
            return crow::response(400);
        std::ostringstream os;
        os << count << " bottles of beer!";
        return crow::response(os.str());
    });

    // Compile error with message "Handler type is mismatched with URL paramters"
    //CROW_ROUTE(app,"/another/<int>")
    //([](int a, int b){
        //return crow::response(500);
    //});

    // more json example
    // e.g. curl -X POST -H 'X-TEST-Header: MyGoodness' http://127.0.0.1:8080/add_json -d '{"a": 1, "b": 3, "message": "Hello!"}'
    CROW_ROUTE(app, "/add_json")
    .methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body);

        // Get header value for X-TEST-Header
        string header_str = req.get_header_value("X-TEST-Header");

        if (!x)
            return crow::response(400);
        int sum = x["a"].i()+x["b"].i();
        string message = x["message"].s();

        std::ostringstream os;
        os << message << " " << sum << " " << header_str;
        return crow::response{os.str()};
    });

    // Limit to only POST and GET
    // To test:-
    // curl -X GET http://127.0.0.1:8080/multi_method
    // curl -X POST http://127.0.0.1:8080/multi_method
    CROW_ROUTE(app, "/multi_method")
    .methods("POST"_method, "GET"_method)
    ([](const crow::request& req){

        // get the METHOD name
        string method_name = crow::method_name(req.method);

        std::ostringstream os;
        os << method_name;
        return crow::response{os.str()};
    });

    app.port(8080)
        .multithreaded()
        .run();
}
