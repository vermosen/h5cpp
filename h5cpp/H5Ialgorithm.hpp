/*
 * Copyright (c) 2018 vargaconsulting, Toronto,ON Canada
 * Author: Varga, Steven <steven@vargaconsulting.ca>
 *
 */

#ifndef  H5CPPI_ALGORITHM_HPP
#define  H5CPPI_ALGORITHM_HPP


namespace h5 { namespace impl {
	inline static herr_t iterate_callback( ::hid_t gid, const char *name, const H5L_info_t *info, void *op_data){

		std::vector<std::string> *data =  static_cast<std::vector<std::string>* >(op_data);
		data->push_back( std::string(name) );
		return 0;
	}

}}

namespace h5 {
    inline std::vector<std::string> ls(const h5::fd_t& fd,  const std::string& directory ){
        hid_t group_id = H5Gopen( static_cast<hid_t>(fd), directory.c_str(), H5P_DEFAULT );
        std::vector<std::string> files;
            H5Literate( group_id, H5_INDEX_NAME, H5_ITER_INC, 0, &impl::iterate_callback, &files );
		H5Gclose(group_id);
        return files;
    }
    inline std::vector<std::string> bfs(const h5::fd_t& fd,  const std::string& directory ){
        std::vector<std::string> files;
        return files;
    }
	inline std::vector<std::string> dfs(const h5::fd_t& fd,  const std::string& directory ){
        std::vector<std::string> files;
        return files;
    }
}

#endif

