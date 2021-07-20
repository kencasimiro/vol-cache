#ifndef _cache_new_h5api_H
#define _cache_new_h5api_H

#include "hdf5.h"
#include "hdf5dev.h"
#include "H5LS.h"

#ifdef __cplusplus
extern "C" {
#endif

/* New "public" API routines */
herr_t H5Dmmap_remap(const char *app_file, const char *app_func, unsigned app_line, hid_t dset_id);
herr_t H5Dprefetch(const char *app_file, const char *app_func, unsigned app_line, hid_t dset_id,
                   hid_t file_space_id, hid_t dxpl_id);
herr_t H5Dprefetch_async(const char *app_file, const char *app_func, unsigned app_line, hid_t dset_id,
                         hid_t file_space_id, hid_t dxpl_id, hid_t es_id);
herr_t H5Dread_to_cache(const char *app_file, const char *app_func, unsigned app_line, hid_t dset_id,
                        hid_t mem_type_id, hid_t memspace_id, hid_t file_space_id, hid_t dxpl_id, void *buf);
herr_t H5Dread_to_cache_async(const char *app_file, const char *app_func, unsigned app_line, hid_t dset_id,
                              hid_t mem_type_id, hid_t memspace_id, hid_t file_space_id, hid_t dxpl_id,
                              void *buf, hid_t es_id);
herr_t H5Dread_from_cache(const char *app_file, const char *app_func, unsigned app_line, hid_t dset_id,
                          hid_t mem_type_id, hid_t memspace_id, hid_t file_space_id, hid_t dxpl_id,
                          void *buf);
herr_t H5Dread_from_cache_async(const char *app_file, const char *app_func, unsigned app_line, hid_t dset_id,
                                hid_t mem_type_id, hid_t memspace_id, hid_t file_space_id, hid_t dxpl_id,
                                void *buf, hid_t es_id);
herr_t H5Dmmap_remap(const char *app_file, const char *app_func, unsigned app_line, hid_t group_id);
herr_t H5Freserve_cache(const char *app_file, const char *app_func, unsigned app_line, hid_t file_id,
                        hid_t hid_dxpl_id, hsize_t size, cache_purpose_t purpose, cache_duration_t duration);
herr_t H5Fquery_cache(const char *app_file, const char *app_func, unsigned app_line, hid_t file_id,
                      hid_t hid_dxpl_id, hsize_t *size);
herr_t H5Fcache_create(const char *app_file, const char *app_func, unsigned app_line, hid_t file_id,
                       hid_t fapl_id, hsize_t size, cache_purpose_t purpose, cache_duration_t duration);
herr_t H5Fcache_remove(const char *app_file, const char *app_func, unsigned app_line, hid_t file_id);
herr_t H5Dcache_remove(const char *app_file, const char *app_func, unsigned app_line, hid_t dset_id);
herr_t H5Dcache_create(const char *app_file, const char *app_func, unsigned app_line, hid_t dset_id,
                       const char *name);
herr_t H5Fcache_create_async(const char *app_file, const char *app_func, unsigned app_line, hid_t file_id,
                             hid_t fapl_id, hsize_t size, cache_purpose_t purpose, cache_duration_t duration,
                             hid_t es_id);
herr_t H5Fcache_remove_async(const char *app_file, const char *app_func, unsigned app_line, hid_t file_id,
                             hid_t es_id);
herr_t H5Dcache_remove_async(const char *app_file, const char *app_func, unsigned app_line, hid_t dset_id,
                             hid_t es_id);
herr_t H5Dcache_create_async(const char *app_file, const char *app_func, unsigned app_line, hid_t dset_id,
                             char *name, hid_t es_id);
H5_DLL hid_t H5VL_cache_ext_register(void);

#ifndef NEW_H5API_IMPL
#define H5Dmmap_remap(...)            H5Dmmap_remap(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Dfoo(...)                   H5Dfoo(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Dprefetch(...)              H5Dprefetch(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Dprefetch_async(...)        H5Dprefetch_async(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Dread_to_cache(...)         H5Dread_to_cache(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Dread_to_cache_async(...)   H5Dread_to_cache_async(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Dread_from_cache(...)       H5Dread_from_cache(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Dread_from_cache_async(...) H5Dread_from_cache_async(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Dmmap_remap(...)            H5Dmmap_remap(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Freserve_cache(...)         H5Freserve_cache(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Fquery_cache(...)           H5Fquery_cache(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Fcache_create(...)          H5Fcache_create(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Fcache_remove(...)          H5Fcache_remove(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Dcache_remove(...)          H5Dcache_remove(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Dcache_create(...)          H5Dcache_create(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Fcache_create_async(...)    H5Fcache_create_async(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Fcache_remove_async(...)    H5Fcache_remove_async(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Dcache_remove_async(...)    H5Dcache_remove_async(__FILE__, __func__, __LINE__, __VA_ARGS__)
#define H5Dcache_create_async(...)    H5Dcache_create_async(__FILE__, __func__, __LINE__, __VA_ARGS__)
#endif /* NEW_H5API_IMPL */
#ifdef __cplusplus
}
#endif

#endif
