#ifndef MY_FIELD_FIELD_HPP
#define MY_FIELD_FIELD_HPP
namespace MyField {
    class Field {
        public:
        virtual Field operator + (const Field& element) = 0;
        virtual Field operator - (const Field& element) = 0;
        virtual Field operator * (const Field& element) = 0;
        virtual Field operator / (const Field& element) = 0;
        virtual Field& operator ++ () = 0;
        virtual Field& operator -- () = 0;
    };
}
#endif