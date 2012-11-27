#ifndef _STRUCTS_
#define _STRUCTS_


typedef struct super_block {
    uint32_t s_ninodes;      /* # usable inodes on the minor device */
    int32_t  s_nzones;      /* total device size, including bit maps etc */
    int16_t s_imap_blocks;      /* # of blocks used by inode bit map */
    int16_t s_zmap_blocks;        /* # of blocks used by zone bit map */
    int32_t s_firstdatazone_old;  /* number of first data zone (small) */
    int16_t s_log_zone_size;  /* log2 of blocks/zone */
    uint16_t s_flags;   /* FS state flags */
    uint32_t s_max_size;       /* maximum file size on this device */
    uint32_t s_zones;       /* number of zones (replaces s_nzones in V2) */
    int16_t s_magic;      /* magic number to recognize super-blocks */

    /* The following items are valid on disk only for V3 and above */

    /* The block size in bytes. Minimum MIN_BLOCK SIZE. SECTOR_SIZE
    * multiple. If V1 or V2 filesystem, this should be
    * initialised to STATIC_BLOCK_SIZE.
    */

    int16_t s_pad2;            /* try to avoid compiler-dependent padding */
    uint16_t s_block_size;   /* block size in bytes. */
    uint8_t s_disk_version;     /* filesystem format sub-version */
    /* The following items are only used when the super_block is in memory.
    * If this ever changes, i.e. more fields after s_disk_version has to go to
    * disk, update LAST_ONDISK_FIELD in super.c as that controls which part of the
    * struct is copied to and from disk.
    */
    
    /*struct inode *s_isup;*/  /* inode for root dir of mounted file sys */
    /*struct inode *s_imount;*/   /* inode mounted on */
    uint32_t s_inodes_per_block;   /* precalculated from magic number */
    uint32_t s_firstdatazone;  /* number of first data zone (big) */
    int16_t s_dev;           /* whose super block is this? */
    int32_t s_rd_only;       /* set to 1 iff file sys mounted read only */
    int32_t s_native;          /* set to 1 iff not byte swapped file system */
    int32_t s_version;       /* file system version, zero means bad magic */
    int32_t s_ndzones;     /* # direct zones in an inode */
    int32_t s_nindirs;       /* # indirect zones per indirect block */
    uint32_t s_isearch;       /* inodes below this bit number are in use */
    uint32_t s_zsearch;     /* all zones below this bit number are in use*/
    uint8_t s_is_root;
} superblock;


struct part_entry {
    uint8_t bootind;    /* boot indicator 0/ACTIVE_FLAG  */
    uint8_t start_head;   /* head value for first sector   */
    uint8_t start_sec;  /* sector value + cyl bits for first sector */
    uint8_t start_cyl;    /* track value for first sector  */
    uint8_t sysind;     /* system indicator      */
    uint8_t last_head;    /* head value for last sector    */
    uint8_t last_sec;   /* sector value + cyl bits for last sector */
    uint8_t last_cyl; /* track value for last sector   */
    uint32_t lowsec;     /* logical first sector      */
    uint32_t size;     /* size of partition in sectors  */
};
