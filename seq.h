#ifndef __SEQ
#define __SEQ

// Provide a mapping back to ATGC
#define	DB_MASK			3

// Note that these definitions *must* match nuc_cruc.h
#define	DB_A			0 	// NucCruc::A
#define	DB_C			1 	// NucCruc::C
#define	DB_G			2 	// NucCruc::G
#define	DB_T			3 	// NucCruc::T

#define	DB_MAX_ATGC		DB_T

#define	DB_I			4 	// NucCruc::I, inosine

// IUPAC degenerate nucleotide codes
#define	DB_M			5 	// A or C
#define	DB_R			6 	// G or A
#define	DB_S			7 	// G or C
#define	DB_V			8 	// G or C or A
#define	DB_W			9 	// A or T
#define	DB_Y			10 	// T or C
#define	DB_H			11	// A or C or T
#define	DB_K			12	// G or T
#define	DB_D			13	// G or A or T
#define	DB_B			14	// G or T or C
#define	DB_N			15	// A or T or G or C

#define	DB_GAP			16
#define	DB_UNKNOWN		17

typedef unsigned char SEQBASE;
typedef	unsigned char*	SEQPTR;

// The first base of a sequence starts after the size (an unsigned int)
#define	SEQ_START(PTR)	( PTR + sizeof(unsigned int) )

// The first sizeof(unsigned int) bytes hold the sequence size (number of
// bases)
#define	SEQ_SIZE(PTR)	( *( (unsigned int*)PTR) )

// Every sequence record has the format:
// [sequence size (as an unsigned int)][sequence data]
#define	SEQ_HEADER_SIZE	sizeof(unsigned int)

inline char hash_base_to_ascii(const unsigned char &m_base)
{
	switch(m_base){
		case DB_A:
			return 'A';
		case DB_C:
			return 'C';
		case DB_G:
			return 'G';
		case DB_T:
			return 'T';
		case DB_I:
			return 'I';
		case DB_M:
			return 'M';
		case DB_R:
			return 'R';
		case DB_S:
			return 'S';
		case DB_V:
			return 'V';
		case DB_W:
			return 'W';
		case DB_Y:
			return 'Y';
		case DB_H:
			return 'H';
		case DB_K:
			return 'K';
		case DB_D:
			return 'D';
		case DB_B:
			return 'B';
		case DB_N:
			return 'N';
		case DB_GAP:
			return '-';
		default:
			throw ":hash_base_to_ascii: Illegal base";
	};
	
	// Should never get here
	return -1;
}

inline char hash_base_to_ascii_complement(const unsigned char &m_base)
{
	switch(m_base){
		case DB_A:
			return 'T';
		case DB_C:
			return 'G';
		case DB_G:
			return 'C';
		case DB_T:
			return 'A';
		case DB_I: // The complement of I is ... I
			return 'I';
		case DB_M:
			return 'K';
		case DB_R:
			return 'Y';
		case DB_S: // Complement of G or C is C or G
			return 'S';
		case DB_V:
			return 'B';
		case DB_W: // Complement of A or T is T or A
			return 'W';
		case DB_Y:
			return 'R';
		case DB_H:
			return 'D';
		case DB_K:
			return 'M';
		case DB_D:
			return 'H';
		case DB_B:
			return 'V';
		case DB_N: // Complement of A or T or G or C is T or A or C or G
			return 'N';
		case DB_GAP:
			return '-';
		default:
			throw ":hash_base_to_ascii_complement: Illegal base";
	};
	
	// Should never get here
	return -1;
}

#endif // __SEQ
