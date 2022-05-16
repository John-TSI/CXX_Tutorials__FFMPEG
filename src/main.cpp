#include<iostream>

extern "C"
{
    #include<libavformat/avformat.h>
    #include<libavcodec/avcodec.h>
}


int seeStreams(const char* filename)
{
    AVFormatContext* pFormatContext = avformat_alloc_context();
    if(!pFormatContext)
    {
        std::cout << "Could not create format context." << std::endl;
        return 1;
    }

    int open_file_success = avformat_open_input(&pFormatContext, filename, NULL, NULL);
    if(open_file_success != 0)
    {
        std::cout << "Could not open file and populate AVFormatContext." << std::endl;
        return 1;
    }

    for(int i=0; i<pFormatContext->nb_streams; i++)
    {
        /*auto*/ AVStream* stream = pFormatContext->streams[i];
        
        AVCodecParameters* pCodecParameters = stream->codecpar;
        AVCodec* pCodec = avcodec_find_decoder(pCodecParameters->codec_id);
        if(pCodec == NULL)
        {
            std::cout << "ERROR: unsupported codec." << std::endl;
            return 1;
        }

        switch(pCodecParameters->codec_type)
        {
            case AVMEDIA_TYPE_VIDEO:
            {
                std::cout << "Stream " << i << " is a Video stream." << std::endl;
                break;
            }
            case AVMEDIA_TYPE_AUDIO:
            {
                std::cout << "Stream " << i << " is an Audio stream." << std::endl;
                break;
            }
        }

        std::cout << "Codec ID: " << pCodecParameters->codec_id << std::endl;
        std::cout << "Codec Name: " << pCodec->long_name << std::endl;
        std::cout << "Stream duration: " << stream->duration << std::endl;
        std::cout << "Stream framerate: " << stream->r_frame_rate.num << std::endl;
    }

    return 0;
}

int main()
{
    //const char* filename = "C:\\Users\\local_admin\\Downloads\\SampleVideo_1280x720_1mb.mp4";
    const char* filename = R"(C:\Users\local_admin\Downloads\SampleVideo_1280x720_1mb.mp4)";

    seeStreams(filename);

    std::cout << "Program terminated without issues!" << std::endl;

    return 0;
}