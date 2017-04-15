#include <person.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>


class Session {
public:
    Session()
    {
    }
    static std::unique_ptr<Session> create_session()
    {
        return std::make_unique<Session>();
    }
    unsigned id() const { return m_id; }
private:
    unsigned m_id = 0;
};

std::ostream& operator<<(std::ostream& out, const Session& s)
{
    return out << s.id();
}

class Response {
public:
    Response(const std::string& data)
        : m_data{data}
    {
    }
    std::string data() const { return m_data; }
private:
    std::string m_data;
};

class Request {
public:
    Request(const std::string& r, unsigned id)
        : m_r{r}
        , m_id{id}
    {
    }

    template<typename Handler>
    void on_completed(Handler h)
    {
        h(Response{"ok"});
    }
private:
    std::string m_r;
    unsigned m_id;
};

std::ostream& operator<<(std::ostream& out, const Response& r)
{
    return out << r.data();
}

class Server {
public:
    Request request(const std::string& r, unsigned id)
    {
        return Request(r, id);
    }
};

unsigned current_time()
{
    static unsigned time = 0;
    return time++;
}


int main()
{
    auto people = std::vector<Person>{
        {"Peter", false, 56},
        {"Martha", true, 24},
        {"Jane", true, 52},
        {"David", false, 84},
        {"Tom", false, 32},
        {"Rose", true, 31}
    };

    auto females = std::vector<Person>{};

    std::copy_if(people.cbegin(), people.cend(),
                 std::back_inserter(females),
                 [](const Person& person) {
                     return person.isFemale();
                 });

    std::cout << "Female person names: \n";
    for (auto person: females) {
        std::cout << person.name() << '\n';
    }


    // C++14: generalized lambda captures
    auto server = Server{};
    auto session = Session::create_session();
    auto request = server.request("GET /", session->id());

    request.on_completed(
        [session = std::move(session),
         time = current_time()
        ]
        (const Response& response)
        {
            std::cout << "Got response: " << response
                      << " for session: " << *session
                      << " the request took: "
                      << (current_time() - time)
                      << " milliseconds"
                      << '\n';
        }
    );
}
