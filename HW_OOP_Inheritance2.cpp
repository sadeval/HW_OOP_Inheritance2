#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Passport {
protected:
    string fullName;
    string passportNumber;

public:
    void SetFullName(string fullName) {
        this->fullName = fullName;
    }

    string GetFullName() const {
        return fullName;
    }

    void SetPassportNumber(string passportNumber) {
        this->passportNumber = passportNumber;
    }

    string GetPassportNumber() const {
        return passportNumber;
    }

    Passport(string fullName, string passportNumber) {
        SetFullName(fullName);
        SetPassportNumber(passportNumber);
        cout << "Passport C-TOR\n";
    }

    ~Passport() {
        cout << "Passport D-TOR\n";
    }

    void Print() const {
        cout << "Full Name: " << fullName << "\nPassport Number: " << passportNumber << "\n";
    }
};

class Visa {
protected:
    string country;
    string expirationDate;

public:
    void SetCountry(string country) {
        this->country = country;
    }

    string GetCountry() const {
        return country;
    }

    void SetExpirationDate(string expirationDate) {
        this->expirationDate = expirationDate;
    }

    string GetExpirationDate() const {
        return expirationDate;
    }

    Visa(string country, string expirationDate) {
        SetCountry(country);
        SetExpirationDate(expirationDate);
        cout << "Visa C-TOR\n";
    }

    ~Visa() {
        cout << "Visa D-TOR\n";
    }

    void Print() const {
        cout << "Country: " << country << ", Expiration Date: " << expirationDate << "\n";
    }
};

class ForeignPassport : public Passport {
protected:
    vector<Visa> visas;

public:
    void SetVisas(const vector<Visa>& visas) {
        this->visas = visas;
    }

    vector<Visa> GetVisas() const {
        return visas;
    }

    ForeignPassport(string fullName, string passportNumber, const vector<Visa>& visas) : Passport(fullName, passportNumber) {
        SetVisas(visas);
        cout << "Foreign Passport C-TOR\n";
    }

    ~ForeignPassport() {
        cout << "Foreign Passport D-TOR\n";
    }

    void Print() const {
        Passport::Print();
        cout << "Visas:\n";
        for (const auto& visa : visas) {
            visa.Print();
        }
    }
};

int main() {
    Passport passport("Mykola Veresen", "001234567");
    passport.Print();

    vector<Visa> visas = { Visa("USA", "31.12.2024"), Visa("UK", "15.10.2025") };
    ForeignPassport foreignPassport("Mykola Veresen", "FL123456", visas);
    foreignPassport.Print();
}

