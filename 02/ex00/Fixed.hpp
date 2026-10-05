#pragma once

class   Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed &operator=(const Fixed& other);
        ~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

    private:
        int                 _fixedPoint;
        static const int    _nbFractBits = 8;
};
