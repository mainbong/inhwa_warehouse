#include <stdio.h>
#include <media/AudioTrack.h>

using namespace android;

#define ID_RIFF 0x46464952
#define ID_WAVE 0x45564157
#define ID_FMT  0x20746d66
#define ID_DATA 0x61746164

struct riff_wave_header {
	uint32_t riff_id;
	uint32_t riff_sz;
	uint32_t wave_id;
};

struct chunk_header {
	uint32_t id;
	uint32_t sz;
};

struct chunk_fmt {
	uint16_t audio_format;
	uint16_t num_channels;
	uint32_t sample_rate;
	uint32_t byte_rate;
	uint16_t block_align;
	uint16_t bits_per_sample;
};

int main()
{
	char buffer[1024] = {0,};
	int num_read;
	FILE *file;
	struct riff_wave_header riff_wave_header;
	struct chunk_header chunk_header;
	struct chunk_fmt chunk_fmt;
	unsigned int device = 0;
	unsigned int card = 0;
	unsigned int period_size = 1024;
	unsigned int period_count = 4;
	const char *filename = "a.wav";
	int more_chunks = 1;

	file = fopen(filename, "rb");
	fread(&riff_wave_header, sizeof(riff_wave_header), 1, file);
	do {
		fread(&chunk_header, sizeof(chunk_header), 1, file);

		switch (chunk_header.id) {
			case ID_FMT:
				fread(&chunk_fmt, sizeof(chunk_fmt), 1, file);
				/* If the format header is larger, skip the rest */
				if (chunk_header.sz > sizeof(chunk_fmt))
					fseek(file, chunk_header.sz - sizeof(chunk_fmt), SEEK_CUR);
				break;
			case ID_DATA:
				/* Stop looking for chunks */
				more_chunks = 0;
				break;
			default:
				/* Unknown chunk, skip bytes */
				fseek(file, chunk_header.sz, SEEK_CUR);
		}
	} while (more_chunks);

	sp<AudioTrack> lpTrack = new AudioTrack();
	lpTrack->set( AUDIO_STREAM_DEFAULT, 44100, AUDIO_FORMAT_DEFAULT, 0 );
	lpTrack->start();
	while( num_read = fread( buffer, 1, sizeof buffer, file )) 
		lpTrack->write( buffer, num_read );

	return 0;
}














