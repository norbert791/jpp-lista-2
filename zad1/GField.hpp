#ifndef GField_HPP
#define GField_HPP

namespace MyFields {
    template<unsigned long long N>
    class GField final{
        public:
        GField operator + (const unsigned long long &GField<N> number);
        GField operator - (const unsigned long long &GField<N> number);
        GField operator * (const unsigned long long &GField<N> number);
        GField operator / (const unsigned long long &GField<N> number);
        &GField operator ++ ();
        &GField operator -- ();
        private:
        const unsigned long long value;
    };
}

#endif /* GField_HPP*/