OBJS = tntblast.o degenerate_na.o primer.o input.o nuc_cruc_anchor.o \
	nuc_cruc.o nuc_cruc_output.o nuc_cruc_santa_lucia.o bind_oligo.o \
	amplicon_search.o probe_search.o padlock_search.o tntblast_master.o \
	tntblast_worker.o tntblast_util.o options.o tntblast_local.o bitmask.o \
	sequence_data.o sequence_data_annot.o annotation.o annotation_embl.o \
	annotation_gbk.o annotation_ptt.o annotation_util.o annotation_gff3.o gff3.o \
	sequence_data_fastx.o ncbi_util.o tntblast_timer.o

CC = mpic++

PROFILE = #-pg
OPENMP = #-Xpreprocessor -fopenmp

# Define USE_MPI to enable MPI
# Define USE_BLAST_DB to enable the reading of Blast-formatted databases
FLAGS = $(PROFILE) -O3 -Wall $(OPENMP) -std=c++11 -DUSE_MPI -DUSE_BLAST_DB

# These variables only need to be defined if USE_BLAST_DB is defined
BLAST_DIR = ncbi-blast-2.10.0+-src
BLAST_INC = $(BLAST_DIR)/include/ncbi-tools++
BLAST_LIBS = -L $(BLAST_DIR)/lib \
	-ldl -lseqdb -lxobjmgr -lblastdb -lgeneral -lgenome_collection -llmdb \
	-lseq -lpub -lmedline -lseqcode -lseqset -lsequtil -lxser -lxutil -lxncbi -lsubmit -lbiblio
	
INC = -I. -I$(BLAST_INC)

LIBS = -lm $(BLAST_LIBS)

.SUFFIXES : .o .cpp .c
.cpp.o:
	$(CC) $(FLAGS) $(INC) -c $<

all: tntblast

tntblast : $(OBJS)
	$(CC) $(PROFILE) -o tntblast $(OBJS) $(LIBS) $(OPENMP)

clean:
	-rm -f *.o


